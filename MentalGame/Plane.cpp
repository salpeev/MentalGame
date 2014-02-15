//
//  Plane.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Plane.h"



namespace Renderer {
    
    Plane::Plane(const Point &a, const Point &b, const Point &c) {
        Vector3 ab = b - a;
        Vector3 ac = c - a;
        
        m_normal = ab.Cross(ac);
        m_normal.Normalize();
        
        m_distance = m_normal.Dot(a);
    }
    
    const Vector3 & Plane::GetNormal() const {
        return m_normal;
    }
    
    float Plane::GetDistance() const {
        return m_distance;
    }
}
