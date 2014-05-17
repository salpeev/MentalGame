//
//  Camera.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 14.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Camera.h"
#include "Logger.h"
#include "Constants.h"



namespace Renderer {
    
    Camera::Camera(float width, float height) {
        m_resolution = CSize(width, height);
    }
    
    Camera::~Camera() {
        
    }
    
    void Camera::Initialize() const {
        Framebuffer *framebuffer = GetFramebuffer();
        Renderbuffer *colorRenderbuffer = GetColorRenderbuffer();
        Renderbuffer *depthRenderbuffer = GetDepthRenderbuffer();
        Renderbuffer *stencilRenderbuffer = GetStencilRenderbuffer();
        
        colorRenderbuffer->EstablishStorage(m_resolution.width, m_resolution.height);
        depthRenderbuffer->EstablishStorage(m_resolution.width, m_resolution.height);
        stencilRenderbuffer->EstablishStorage(m_resolution.width, m_resolution.height);
        
        framebuffer->AttachColorRenderbuffer(colorRenderbuffer);
        framebuffer->AttachDepthRenderbuffer(depthRenderbuffer);
        framebuffer->AttachStencilRenderbuffer(stencilRenderbuffer);
    }
    
    void Camera::SetViewport(const Rect &rViewport) const {
        glViewport(rViewport.origin.x, rViewport.origin.y, rViewport.size.width, rViewport.size.height);
        CheckError();
    }
    
    Rect Camera::GetViewport() const {
        Rect viewport;
        glGetFloatv(GET_PARAMETER_VIEWPORT, (float *)(&viewport));
        CheckError();
        
        return viewport;
    }
}