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
    
    Camera::Camera(float width, float height, const Projection &rProjection) {
        m_resolution = CSize(width, height);
        SetViewport(Rect(0.0f, 0.0f, width, height));
        SetProjection(rProjection);
    }
    
    Camera::~Camera() {
        
    }
    
    void Camera::Initialize() const {
        Framebuffer *framebuffer = GetFramebuffer();
        Texture2D *texture2D = GetTexture2D();
        Renderbuffer *colorRenderbuffer = GetColorRenderbuffer();
        Renderbuffer *depthRenderbuffer = GetDepthRenderbuffer();
        Renderbuffer *stencilRenderbuffer = GetStencilRenderbuffer();
        
        if (colorRenderbuffer) {
            colorRenderbuffer->EstablishStorage(m_resolution.width, m_resolution.height);
            framebuffer->AttachColorRenderbuffer(colorRenderbuffer);
        } else if (texture2D) {
            framebuffer->AttachTexture2D(texture2D);
        }
        
        depthRenderbuffer->EstablishStorage(m_resolution.width, m_resolution.height);
        stencilRenderbuffer->EstablishStorage(m_resolution.width, m_resolution.height);
        
        framebuffer->AttachDepthRenderbuffer(depthRenderbuffer);
        framebuffer->AttachStencilRenderbuffer(stencilRenderbuffer);
    }
    
    void Camera::Enable() const {
        GetFramebuffer()->BindAll();
        GetFramebuffer()->Clear();
    }
    
    CSize Camera::GetResolution() const {
        return m_resolution;
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
    
    void Camera::SetProjection(const Projection &rProjection) {
        m_projection = rProjection;
    }
    
    const Projection & Camera::GetProjection() const {
        return m_projection;
    }
    
    Texture2D * Camera::GetTexture2D() const {
        return nullptr;
    }
    
    Renderbuffer * Camera::GetColorRenderbuffer() const {
        return nullptr;
    }
    
    Renderbuffer * Camera::GetDepthRenderbuffer() const {
        return nullptr;
    }
    
    Renderbuffer * Camera::GetStencilRenderbuffer() const {
        return nullptr;
    }
}