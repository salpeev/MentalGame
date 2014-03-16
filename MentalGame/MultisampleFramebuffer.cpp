//
//  MultisampleFramebuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 30.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "MultisampleFramebuffer.h"
#include "GLConstants.h"
#include "Logger.h"
#include <OpenGLES/ES2/glext.h>



namespace Renderer {
    
#pragma mark - Public Methods
    
    void MultisampleFramebuffer::BindDrawApple() const {
        if (!IsBoundDrawApple()) {
            // TODO: This call produces warning when depth and stencil buffers bound
            glBindFramebuffer(GL_DRAW_FRAMEBUFFER_APPLE, GetName());
            CheckError();
        }
    }
    
    void MultisampleFramebuffer::BindReadApple() const {
        if (!IsBoundReadApple()) {
            glBindFramebuffer(GL_READ_FRAMEBUFFER_APPLE, GetName());
            CheckError();
        }
    }
    
    void MultisampleFramebuffer::DiscardReadApple() const {
        if (GetColorRenderbuffer()) {
            const GLenum attachment[1] = {FRAMEBUFFER_ATTACHMENT_COLOR0};
            glDiscardFramebufferEXT(GL_READ_FRAMEBUFFER_APPLE, 1, attachment);
        }
        if (GetDepthRenderbuffer()) {
            const GLenum attachment[1] = {FRAMEBUFFER_ATTACHMENT_DEPTH};
            glDiscardFramebufferEXT(GL_READ_FRAMEBUFFER_APPLE, 1, attachment);
        }
        if (GetStencilRenderbuffer()) {
            const GLenum attachment[1] = {FRAMEBUFFER_ATTACHMENT_STENCIL};
            glDiscardFramebufferEXT(GL_READ_FRAMEBUFFER_APPLE, 1, attachment);
        }
    }
    
    void MultisampleFramebuffer::ResolveMultisampleApple() {
        glResolveMultisampleFramebufferAPPLE();
    }
    
#pragma mark - Private Methods
    
    bool MultisampleFramebuffer::IsBoundDrawApple() const {
        GLint currentFramebufferName;
        glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING_APPLE, &currentFramebufferName);
        
        bool bound = (currentFramebufferName == GetName());
        return bound;
    }
    
    bool MultisampleFramebuffer::IsBoundReadApple() const {
        GLint currentFramebufferName;
        glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING_APPLE, &currentFramebufferName);
        
        bool bound = (currentFramebufferName == GetName());
        return bound;
    }
}
