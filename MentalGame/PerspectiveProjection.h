//
//  Projection.h
//  MentalGame
//
//  Created by Sergey Alpeev on 18.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Projection.h"



namespace Renderer {
    
    class PerspectiveProjection: public Projection {
    public:
        PerspectiveProjection();
        PerspectiveProjection(float left, float right, float bottom, float top, float near, float far);
        PerspectiveProjection(float fovy, float aspect, float near, float far);
        
        void SetFrustum(float left, float right, float bottom, float top, float near, float far);
        void SetFrustum(float fovy, float aspect, float near, float far);
        
        float GetDistance() const;
        Rect GetFrontRect() const;
        Matrix4 GetProjectionMatrix() const;
        
    private:
        float m_distance;
        Rect m_frontRect;
        Matrix4 m_projectionMatrix;
    };
}
