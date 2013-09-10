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
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h>

using namespace Renderer;



@interface MGOpenGLView ()
{
    RenderingEngine *m_renderingEngine;
    
    GLuint m_resolveFramebuffer;
    GLuint m_sampleFramebuffer;
    GLuint m_resolveColorRenderbuffer;
    GLuint m_sampleColorRenderbuffer;
    GLuint m_sampleDepthStencilRenderbuffer;
}

@property (strong, nonatomic) EAGLContext *eaglContext;

- (void)draw:(CADisplayLink *)displayLink;

@end



@implementation MGOpenGLView

#pragma mark - Class Methods

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

#pragma mark - Lifecycle

- (id)initWithFrame:(CGRect)frame
{
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
        
        glGenRenderbuffers(1, &m_resolveColorRenderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_resolveColorRenderbuffer);
        [self.eaglContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
        
        glGenFramebuffers(1, &m_resolveFramebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, m_resolveFramebuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_resolveColorRenderbuffer);
        
        glGenRenderbuffers(1, &m_sampleColorRenderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_sampleColorRenderbuffer);
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_RGBA8_OES, width, height);
        
        glGenRenderbuffers(1, &m_sampleDepthStencilRenderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_sampleDepthStencilRenderbuffer);
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8_OES, width, height);
        
        glGenFramebuffers(1, &m_sampleFramebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, m_sampleFramebuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_sampleColorRenderbuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_sampleDepthStencilRenderbuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_sampleDepthStencilRenderbuffer);
        
        m_renderingEngine = new RenderingEngine(width, height);
        
        CADisplayLink *displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(draw:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    }
    return self;
}

- (void)dealloc
{
    delete m_renderingEngine;
}

#pragma mark - Private Methods

- (void)draw:(CADisplayLink *)displayLink
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_sampleFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_sampleColorRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_sampleDepthStencilRenderbuffer);
    
    m_renderingEngine->Render();
    
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER_APPLE, m_resolveFramebuffer);
    glBindFramebuffer(GL_READ_FRAMEBUFFER_APPLE, m_sampleFramebuffer);
    glResolveMultisampleFramebufferAPPLE();
    
    const GLenum discards[] =
    {
        GL_COLOR_ATTACHMENT0,
        GL_DEPTH_ATTACHMENT,
        GL_STENCIL_ATTACHMENT
    };
    glDiscardFramebufferEXT(GL_READ_FRAMEBUFFER_APPLE, 3, discards);
    
    glBindFramebuffer(GL_FRAMEBUFFER, m_resolveFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_resolveColorRenderbuffer);
    
    [self.eaglContext presentRenderbuffer:GL_RENDERBUFFER];
}

@end
