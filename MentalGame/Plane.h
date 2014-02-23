//
//  Plane.h
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Matrix.h"



namespace Renderer {
    
    class Plane {
    public:
        Plane(const Point &a, const Point &b, const Point &c);
        
        Plane Transformed(Matrix4 &rMatrix) const;
        void Transform(Matrix4 &rMatrix);
        
        const Vector3 & GetNormal() const;
        float GetDistance() const;
        Point GetPosition() const;
        
    private:
        Vector3 m_normal;
        float m_distance;
    };
}
