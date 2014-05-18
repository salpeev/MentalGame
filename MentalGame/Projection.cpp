//
//  Projection.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 18.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Projection.h"



namespace Renderer {
    
    Projection::Projection(): m_distance(0.0f) {
        
    }
    
    Projection::Projection(float left, float right, float bottom, float top, float near, float far, bool orthogonal) {
        SetFrustum(left, right, bottom, top, near, far, orthogonal);
    }
    
    Projection::Projection(float fovy, float aspect, float near, float far) {
        SetFrustum(fovy, aspect, near, far);
    }
    
    void Projection::SetFrustum(float left, float right, float bottom, float top, float near, float far, bool orthogonal) {
        float width = right - left;
        float height = top - bottom;
        m_frontRect = Rect(left, bottom, width, height);
        m_distance = -near;
        
        if (orthogonal) {
            m_projectionMatrix = Matrix4::Ortho(left, right, bottom, top, near, far);
        } else {
            m_projectionMatrix = Matrix4::Frustum(left, right, bottom, top, near, far);
        }
    }
    
    void Projection::SetFrustum(float fovy, float aspect, float near, float far) {
        float halfY = near * tan(fovy / 2.0f);
        float halfX = aspect * halfY;
        m_frontRect = Rect(-halfX, -halfY, halfX * 2.0f, halfY * 2.0f);
        m_distance = -near;
        
        m_projectionMatrix = Matrix4::Frustum(fovy, aspect, near, far);
    }
    
    float Projection::GetDistance() const {
        return m_distance;
    }
    
    Rect Projection::GetFrontRect() const {
        return m_frontRect;
    }
    
    Matrix4 Projection::GetProjectionMatrix() const {
        return m_projectionMatrix;
    }
}