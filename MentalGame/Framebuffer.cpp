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
    
    Framebuffer::Framebuffer(): m_name(0), m_colorRenderbuffer(nullptr), m_depthRenderbuffer(nullptr), m_stencilRenderbuffer(nullptr) {
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
    
    void Framebuffer::BindAll() const {
        Bind();
        BindColorRenderbuffer();
        BindDepthRenderbuffer();
        BindStencilRenderbuffer();
    }
    
    void Framebuffer::Clear() const {
        // TODO: Check is framebuffer should be bound. Is renderbuffers should be bound too?
        Bind();
        
        GLbitfield mask = 0;
        
        if (GetColorRenderbuffer()) {
            mask |= CLEAR_BUFFER_BIT_COLOR;
        }
        if (GetDepthRenderbuffer()) {
            mask |= CLEAR_BUFFER_BIT_DEPTH;
        }
        if (GetDepthRenderbuffer()) {
            mask |= CLEAR_BUFFER_BIT_STENCIL;
        }
        
        glClear(mask);
        CheckError();
    }
    
    void Framebuffer::Clear(GLbitfield mask) const {
        // TODO: Check is framebuffer should be bound. Is renderbuffers should be bound too?
        Bind();
        
        glClear(mask);
        CheckError();
    }
    
    void Framebuffer::AttachColorRenderbuffer(Renderbuffer *pRenderbuffer) {
        Bind();
        pRenderbuffer->Bind();
        
        GLuint renderbufferName = pRenderbuffer->GetName();
        glFramebufferRenderbuffer(FRAMEBUFFER_OBJECT_FRAMEBUFFER, FRAMEBUFFER_ATTACHMENT_COLOR0, FRAMEBUFFER_OBJECT_RENDERBUFFER, renderbufferName);
        CheckError();
        
        m_colorRenderbuffer = pRenderbuffer;
    }
    
    void Framebuffer::AttachDepthRenderbuffer(Renderbuffer *pRenderbuffer) {
        Bind();
        pRenderbuffer->Bind();
        
        GLuint renderbufferName = pRenderbuffer->GetName();
        glFramebufferRenderbuffer(FRAMEBUFFER_OBJECT_FRAMEBUFFER, FRAMEBUFFER_ATTACHMENT_DEPTH, FRAMEBUFFER_OBJECT_RENDERBUFFER, renderbufferName);
        CheckError();
        
        m_depthRenderbuffer = pRenderbuffer;
    }
    
    void Framebuffer::AttachStencilRenderbuffer(Renderbuffer *pRenderbuffer) {
        Bind();
        pRenderbuffer->Bind();
        
        GLuint renderbufferName = pRenderbuffer->GetName();
        glFramebufferRenderbuffer(FRAMEBUFFER_OBJECT_FRAMEBUFFER, FRAMEBUFFER_ATTACHMENT_STENCIL, FRAMEBUFFER_OBJECT_RENDERBUFFER, renderbufferName);
        CheckError();
        
        m_stencilRenderbuffer = pRenderbuffer;
    }
    
    void Framebuffer::BindColorRenderbuffer() const {
        if (m_colorRenderbuffer) {
            m_colorRenderbuffer->Bind();
        }
    }
    
    void Framebuffer::BindDepthRenderbuffer() const {
        if (m_depthRenderbuffer) {
            m_depthRenderbuffer->Bind();
        }
    }
    
    void Framebuffer::BindStencilRenderbuffer() const {
        if (m_stencilRenderbuffer) {
            m_stencilRenderbuffer->Bind();
        }
    }
    
    void Framebuffer::DetachColorRenderbuffer() {
        Bind();
        
        glFramebufferRenderbuffer(FRAMEBUFFER_OBJECT_FRAMEBUFFER, FRAMEBUFFER_ATTACHMENT_COLOR0, FRAMEBUFFER_OBJECT_RENDERBUFFER, 0);
        CheckError();
        
        m_colorRenderbuffer = nullptr;
    }
    
    void Framebuffer::DetachDepthRenderbuffer() {
        Bind();
        
        glFramebufferRenderbuffer(FRAMEBUFFER_OBJECT_FRAMEBUFFER, FRAMEBUFFER_ATTACHMENT_DEPTH, FRAMEBUFFER_OBJECT_RENDERBUFFER, 0);
        CheckError();
        
        m_depthRenderbuffer = nullptr;
    }
    
    void Framebuffer::DetachStencilRenderbuffer() {
        Bind();
        
        glFramebufferRenderbuffer(FRAMEBUFFER_OBJECT_FRAMEBUFFER, FRAMEBUFFER_ATTACHMENT_STENCIL, FRAMEBUFFER_OBJECT_RENDERBUFFER, 0);
        CheckError();
        
        m_stencilRenderbuffer = nullptr;
    }
    
    Renderbuffer * Framebuffer::GetColorRenderbuffer() const {
        return m_colorRenderbuffer;
    }
    
    Renderbuffer * Framebuffer::GetDepthRenderbuffer() const {
        return m_depthRenderbuffer;
    }
    
    Renderbuffer * Framebuffer::GetStencilRenderbuffer() const {
        return m_stencilRenderbuffer;
    }
    
    void Framebuffer::SetClearColor(const GLColor &rColor) const {
        Bind();
        
        glClearColor(rColor.r, rColor.g, rColor.b, rColor.a);
        CheckError();
    }
    
    void Framebuffer::SetClearDepth(GLclampf depth) const {
        Bind();
        
        glClearDepthf(depth);
        CheckError();
    }
    
    void Framebuffer::SetClearStencil(GLint stencil) const {
        Bind();
        
        glClearStencil(stencil);
        CheckError();
    }
    
    GLColor Framebuffer::GetClearColor() const {
        GLColor color;
        glGetFloatv(GET_PARAMETER_COLOR_CLEAR_VALUE, (GLfloat *)(&color));
        CheckError();
        
        return color;
    }
    
    GLclampf Framebuffer::GetClearDepth() const {
        GLclampf depth;
        glGetFloatv(GET_PARAMETER_DEPTH_CLEAR_VALUE, &depth);
        CheckError();
        
        return depth;
    }
    
    GLint Framebuffer::GetClearStencil() const {
        GLint stencil;
        glGetIntegerv(GET_PARAMETER_STENCIL_CLEAR_VALUE, &stencil);
        CheckError();
        
        return stencil;
    }
    
#pragma mark - Protected Methods
    
    GLuint Framebuffer::GetName() const {
        return m_name;
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
        glGetIntegerv(GET_PARAMETER_FRAMEBUFFER_BINDING, &currentFramebufferName);
        CheckError();
        
        bool bound = (currentFramebufferName == m_name);
        return bound;
    }
}