//
//  Framebuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 27.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Framebuffer.h"
#include "GLConstants.h"
#include "GLLogger.h"



namespace Renderer {
    
    Framebuffer::Framebuffer() {
        Generate();
    }
    
    Framebuffer::~Framebuffer() {
        Delete();
    }
    
#pragma mark - Public Methods
    
    void Framebuffer::Bind() const {
        if (!IsBound()) {
            glBindFramebuffer(FRAMEBUFFER_OBJECT_FRAMEBUFFER, m_name);
            CheckError();
        }
    }
    
#pragma mark - Private Methods
    
    void Framebuffer::Generate() {
        glGenFramebuffers(1, &m_name);
        CheckError();
    }
    
    void Framebuffer::Delete() {
        glDeleteFramebuffers(1, &m_name);
        CheckError();
        
        m_name = 0;
    }
    
    bool Framebuffer::IsBound() const {
        GLint currentFramebufferName;
        glGetIntegerv(GLSL_GET_FRAMEBUFFER_BINDING, &currentFramebufferName);
        CheckError();
        
        bool bound = (currentFramebufferName == m_name);
        return bound;
    }
}