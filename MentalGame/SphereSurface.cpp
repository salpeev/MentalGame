//
//  SphereSurface.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "SphereSurface.h"
#include <cmath>



namespace Renderer {
    
    SphereSurface::SphereSurface(int xDivisions, int yDivisions, float radius): ParametricSurface(xDivisions, yDivisions, M_PI, M_PI * 2.0f), m_radius(radius) {
        
    }
    
    Point3 SphereSurface::Evaluate(const Point3 &domain) const {
        float u = domain.x;
        float v = domain.y;
        
        float x = m_radius * sin(u) * cos(v);
        float y = m_radius * cos(u);
        float z = m_radius * -sin(u) * sin(v);
        
        return Point3(x, y, z);
    }
}