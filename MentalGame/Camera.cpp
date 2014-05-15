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
    
    Camera::Camera() {
        
    }
    
    Camera::~Camera() {
        
    }
    
    void Camera::SetResolution(const CSize &rSize) {
        m_resolution = rSize;
    }
    
    void Camera::SetViewport(const Rect &rViewport) const {
        glViewport(rViewport.origin.x, rViewport.origin.y, rViewport.size.width, rViewport.size.height);
        CheckError();
    }
    
    CSize Camera::GetResolution() const {
        return m_resolution;
    }
    
    Rect Camera::GetViewport() const {
        Rect viewport;
        glGetFloatv(GET_PARAMETER_VIEWPORT, (float *)(&viewport));
        CheckError();
        
        return viewport;
    }
}