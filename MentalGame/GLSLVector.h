//
//  GLSLVector.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <cmath>


namespace Renderer
{
    class GLSLVector2
    {
    public:
        const float * Pointer() const;
        
        float x;
        float y;
    };
    
    
    
    class GLSLVector3
    {
    public:
        const float * Pointer() const;
        
        float x;
        float y;
        float z;
    };
    
    
    
    class GLSLVector4
    {
    public:
        const float * Pointer() const;
        
        float x;
        float y;
        float z;
        float w;
    };
}
