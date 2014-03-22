//
//  Projection.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 18.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Projection.h"



namespace Renderer {
    
    Projection::Projection() {
        
    }
    
    Projection::Projection(float left, float right, float bottom, float top, float near, float far) {
        SetFrustum(left, right, bottom, top, near, far);
    }
    
    Projection::Projection(float fovy, float aspect, float near, float far) {
        SetFrustum(fovy, aspect, near, far);
    }
    
    void Projection::SetFrustum(float left, float right, float bottom, float top, float near, float far) {
        float width = right - left;
        float height = top - bottom;
        m_frontRect = Rect(left, bottom, width, height);
        
        m_projectionMatrix = Matrix4::Frustum(left, right, bottom, top, near, far);
    }
    
    void Projection::SetFrustum(float fovy, float aspect, float near, float far) {
        // TODO: Set front rect
//        m_projection = Matrix4::Frustum(fovy, aspect, near, far);
    }
    
    Rect Projection::GetFrontRect() const {
        return m_frontRect;
    }
    
    Matrix4 Projection::GetProjectionMatrix() const {
        return m_projectionMatrix;
    }
}