//
//  MGOpenGLView.m
//  MentalGame
//
//  Created by Sergey Alpeev on 07.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#import "MGOpenGLView.h"
#import "RenderingEngine.h"
#import "ResourceManager.h"
#import "MultisampleFramebuffer.h"
#include "ColorRenderbufferMultisampleRGBA8.h"
#include "Depth24Stencil8MultisampleRenderbuffer.h"
#include "GameDrawingController.h"
#include "Camera.h"
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
        self.multipleTouchEnabled = YES;
        
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
//        RenderingEngine::SharedInstance().SetProjection(Projection(M_PI_2, aspectRatio, 4.0f, 10.0f));

        CADisplayLink *displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(draw:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
        // TODO: Remove
        Camera *camera = new Camera();
        camera->GetViewport();
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
    vector<Touch *> engineTouches;
    
    CGSize screenSize = [UIScreen mainScreen].bounds.size;
    CGFloat scale = [UIScreen mainScreen].scale;
    for (UITouch *touch in touches) {
        CGPoint touchLocation = [touch locationInView:self.window];
        CGFloat yConverted = screenSize.height - touchLocation.y;
        
        Point2 engineLocation(touchLocation.x * scale, yConverted * scale);
        Touch *engineTouch = new Touch(engineLocation, (__bridge void *)touch);
        engineTouches.push_back(engineTouch);
    }
    
    RenderingEngine::SharedInstance().HandleTouchesBegan(engineTouches);
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    vector<Touch *> movedTouches;
    
    CGSize screenSize = [UIScreen mainScreen].bounds.size;
    CGFloat scale = [UIScreen mainScreen].scale;
    for (UITouch *touch in touches) {
        CGPoint touchLocation = [touch locationInView:self.window];
        CGFloat yConverted = screenSize.height - touchLocation.y;
        
        Touch *engineTouch = RenderingEngine::SharedInstance().GetTouchForSystemTouch((__bridge void *)touch);
        engineTouch->SetWindowPosition(Point2(touchLocation.x * scale, yConverted * scale));
        
        movedTouches.push_back(engineTouch);
    }
    
    RenderingEngine::SharedInstance().HandleTouchesMoved(movedTouches);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    vector<Touch *> endedTouches;
    
    for (UITouch *touch in touches) {
        Touch *engineTouch = RenderingEngine::SharedInstance().GetTouchForSystemTouch((__bridge void *)touch);
        endedTouches.push_back(engineTouch);
    }
    
    RenderingEngine::SharedInstance().HandleTouchesEnded(endedTouches);
    
    for (vector<Touch *>::iterator iterator = endedTouches.begin(); iterator != endedTouches.end(); iterator++) {
        Touch *pTouch = *iterator;
        delete pTouch;
    }
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
    vector<Touch *> cancelledTouches;
    
    for (UITouch *touch in touches) {
        Touch *engineTouch = RenderingEngine::SharedInstance().GetTouchForSystemTouch((__bridge void *)touch);
        cancelledTouches.push_back(engineTouch);
    }
    
    RenderingEngine::SharedInstance().HandleTouchesCancelled(cancelledTouches);
    
    for (vector<Touch *>::iterator iterator = cancelledTouches.begin(); iterator != cancelledTouches.end(); iterator++) {
        Touch *pTouch = *iterator;
        delete pTouch;
    }
}

#pragma mark - Private Methods

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
