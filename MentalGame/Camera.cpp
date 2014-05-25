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
#include "RenderingEngine.h"



namespace Renderer {
    
    Camera::Camera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer): m_resolution(resolution), m_projection(rProjection), m_framebuffer(pFramebuffer) {
        
    }
    
    Camera::~Camera() {
        delete m_framebuffer;
    }
    
    const CSize & Camera::GetResolution() const {
        return m_resolution;
    }
    
    void Camera::SetProjection(const Projection &rProjection) {
        m_projection = rProjection;
    }
    
    Framebuffer * Camera::GetFramebuffer() const {
        return m_framebuffer;
    }
    
    const Projection & Camera::GetProjection() const {
        return m_projection;
    }
    
    void Camera::Record() {
        PrepareForRecord();
        
        m_framebuffer->BindAll();
        m_framebuffer->Clear();
        
        RenderingEngine::SharedInstance().RenderScene();
    }
    
    void Camera::PrepareForRecord() {
        
    }
}