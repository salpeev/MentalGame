//
//  Vector.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <cmath>


namespace Renderer
{
    class Vector2
    {
    public:
        const float * Pointer() const;
        
        float x;
        float y;
    };
    
    
    
    class Vector3
    {
    public:
        const float * Pointer() const;
        
        float x;
        float y;
        float z;
    };
    
    
    
    class Vector4
    {
    public:
        const float * Pointer() const;
        
        float x;
        float y;
        float z;
        float w;
    };
}
