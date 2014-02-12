//
//  Plane.h
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Vector.h"



namespace Renderer {
    
    class Plane {
    public:
        Plane(const Vector3 &a, const Vector3 &b, const Vector3 &c);
        
    private:
        Vector3 m_normal;
        float m_d;
    };
}
