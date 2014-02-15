//
//  Plane.h
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"



namespace Renderer {
    
    class Plane {
    public:
        Plane(const Point &a, const Point &b, const Point &c);
        
        const Vector3 & GetNormal() const;
        float GetDistance() const;
        
    private:
        Vector3 m_normal;
        float m_distance;
    };
}
