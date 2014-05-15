//
//  SphereSurface.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "ParametricSurface.h"



namespace Renderer {
    
    class SphereSurface: public ParametricSurface {
    public:
        SphereSurface(int xDivisions, int yDivisions, float radius);
        
        Point3 Evaluate(const Point3 &domain) const;
        
    private:
        float m_radius;
    };
}
