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
        Plane(const Point3 &a, const Point3 &b, const Point3 &c);
        
        Plane Transformed(Matrix4 &rMatrix, bool translatedRotatedOnly) const;
        void Transform(Matrix4 &rMatrix, bool translatedRotatedOnly);
        
        const Vector3 & GetNormal() const;
        float GetDistance() const;
        Point3 GetPosition() const;
        
    private:
        Vector3 m_normal;
        float m_distance;
    };
}
