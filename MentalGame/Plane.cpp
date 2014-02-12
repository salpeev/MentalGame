//
//  Plane.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Plane.h"



namespace Renderer {
    
    Plane::Plane(const Vector3 &a, const Vector3 &b, const Vector3 &c) {
        Vector3 ab = b - a;
        Vector3 ac = c - a;
        
        m_normal = ab.Cross(ac);
        m_normal.Normalize();
        
        m_d = m_normal.Dot(a);
    }
}
