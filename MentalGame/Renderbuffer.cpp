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
    
    void Renderbuffer::EstablishStorage(int width, int height) {
        if (m_storageEstablished) {
            Log("Renderbuffer storage already established");
            return;
        }
        
        Bind();
        CreateStorage(width, height);
        
        bool errorOccurred = CheckError();
        if (!errorOccurred) {
            m_storageEstablished = true;
        }
    }
    
    void Renderbuffer::Bind() const {
        if (!IsBound()) {
            glBindRenderbuffer(FRAMEBUFFER_OBJECT_RENDERBUFFER, m_name);
            CheckError();
        }
    }
    
    GLuint Renderbuffer::GetName() const {
        return m_name;
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
