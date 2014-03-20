//
//  MGOpenGLView.m
//  MentalGame
//
//  Created by Sergey Alpeev on 07.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#import "MGOpenGLView.h"
#import "RenderingEngine.h"
#import "GLResourceManager.h"
#import "MultisampleFramebuffer.h"
#include "ColorRenderbufferMultisampleRGBA8.h"
#include "Depth24Stencil8MultisampleRenderbuffer.h"
#include "GameDrawingController.h"
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h>

using namespace Renderer;



@interface MGOpenGLView () {
    MultisampleFramebuffer *m_sampleFramebuffer;
    MultisampleFramebuffer *m_resolveFramebuffer;
    Renderbuffer *m_sampleColorRenderbuffer;
    Renderbuffer *m_sampleDepthStencilRenderbuffer;
    Renderbuffer *m_resolveColorRenderbuffer;
}

@property (strong, nonatomic) EAGLContext *eaglContext;

- (vector<Touch>)engineTouhesFromTouches:(NSSet *)touches;

- (void)draw:(CADisplayLink *)displayLink;

@end



@implementation MGOpenGLView

#pragma mark - Class Methods

+ (Class)layerClass {
    return [CAEAGLLayer class];
}

#pragma mark - Lifecycle

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        CGFloat scale = [UIScreen mainScreen].scale;
        CGFloat width = CGRectGetWidth(frame) * scale;
        CGFloat height = CGRectGetHeight(frame) * scale;
        
        CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
        eaglLayer.opaque = YES;
        eaglLayer.contentsScale = scale;
        
        self.eaglContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        [EAGLContext setCurrentContext:self.eaglContext];
        
        m_resolveColorRenderbuffer = new ColorRenderbuffer();
        m_resolveColorRenderbuffer->Bind();
        [self.eaglContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
        
        m_resolveFramebuffer = new MultisampleFramebuffer();
        m_resolveFramebuffer->AttachColorRenderbuffer(m_resolveColorRenderbuffer);
        
        m_sampleColorRenderbuffer = new ColorRenderbufferMultisampleRGBA8();
        m_sampleColorRenderbuffer->EstablishStorage(width, height);
        
        m_sampleDepthStencilRenderbuffer = new Depth24Stencil8MultisampleRenderbuffer();
        m_sampleDepthStencilRenderbuffer->EstablishStorage(width, height);
        
        m_sampleFramebuffer = new MultisampleFramebuffer();
        m_sampleFramebuffer->AttachColorRenderbuffer(m_sampleColorRenderbuffer);
        m_sampleFramebuffer->AttachDepthRenderbuffer(m_sampleDepthStencilRenderbuffer);
//        m_sampleFramebuffer->AttachStencilRenderbuffer(m_sampleDepthStencilRenderbuffer);
        
        float aspectRatio = width / height;
        
        RenderingEngine::SharedInstance().SetFramebuffer(m_sampleFramebuffer);
        RenderingEngine::SharedInstance().SetWindowSize(CSize(width, height));
        RenderingEngine::SharedInstance().SetDrawingController(new GameDrawingController());
        RenderingEngine::SharedInstance().SetProjection(Projection(-2.0f, 2.0f, -2.0f / aspectRatio, 2.0f / aspectRatio, 4.0f, 10.0f));

        CADisplayLink *displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(draw:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];

    }
    return self;
}

- (void)dealloc {
    delete m_sampleFramebuffer;
    delete m_sampleColorRenderbuffer;
    delete m_sampleDepthStencilRenderbuffer;
}

#pragma mark - Overridden

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
//    vector<Touch> engineTouhes = [self engineTouhesFromTouches:touches];
//    RenderingEngine::SharedInstance().TouchesBegan(engineTouhes);
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
//    vector<Touch> engineTouhes = [self engineTouhesFromTouches:touches];
//    RenderingEngine::SharedInstance().TouchesMoved(engineTouhes);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
//    vector<Touch> engineTouhes = [self engineTouhesFromTouches:touches];
//    RenderingEngine::SharedInstance().TouchesEnded(engineTouhes);
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
//    vector<Touch> engineTouhes = [self engineTouhesFromTouches:touches];
//    RenderingEngine::SharedInstance().TouchesCancelled(engineTouhes);
}

#pragma mark - Private Methods

- (vector<Touch>)engineTouhesFromTouches:(NSSet *)touches {
    vector<Touch> engineTouches;
    
    CGFloat scale = [UIScreen mainScreen].scale;
    for (UITouch *touch in touches) {
        CGPoint touchLocation = [touch locationInView:self.window];
        Renderer::Point engineLocation(touchLocation.x * scale, touchLocation.y * scale);
        Touch engineTouch(engineLocation);
        engineTouches.push_back(engineTouch);
    }
    
    return engineTouches;
}

- (void)draw:(CADisplayLink *)displayLink {
    m_sampleFramebuffer->BindAll();
    
    RenderingEngine::SharedInstance().Render(displayLink.duration);
    
    m_resolveFramebuffer->BindDrawApple();
    m_sampleFramebuffer->BindReadApple();
    MultisampleFramebuffer::ResolveMultisampleApple();
    
    m_sampleFramebuffer->DiscardReadApple();
    
    m_resolveFramebuffer->Bind();
    m_resolveFramebuffer->GetColorRenderbuffer()->Bind();
    
    [self.eaglContext presentRenderbuffer:GL_RENDERBUFFER];
}

@end
