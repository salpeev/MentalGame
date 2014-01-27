//
//  Renderbuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 27.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Renderbuffer.h"
#include "GLConstants.h"
#include "GLLogger.h"



namespace Renderer {
    
    Renderbuffer::Renderbuffer() {
        Generate();
    }
    
    Renderbuffer::~Renderbuffer() {
        Delete();
    }
    
#pragma mark - Public Methods
    
    void Renderbuffer::Bind() const {
        if (!IsBound()) {
            glBindRenderbuffer(FRAMEBUFFER_OBJECT_RENDERBUFFER, m_name);
            CheckError();
        }
    }
    
#pragma mark - Private Methods
    
    void Renderbuffer::Generate() {
        glGenRenderbuffers(1, &m_name);
        CheckError();
    }
    
    void Renderbuffer::Delete() {
        glDeleteRenderbuffers(1, &m_name);
        CheckError();
    }
    
    bool Renderbuffer::IsBound() const {
        GLint currentRenderbufferName;
        glGetIntegerv(GL_RENDERBUFFER_BINDING, &currentRenderbufferName);
        CheckError();
        
        bool bound = (currentRenderbufferName == m_name);
        return bound;
    }
}
