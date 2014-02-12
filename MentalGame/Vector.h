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
        Vector2();
        Vector2(float x, float y);
        
        Vector2 operator-(const Vector2 &rVector) const;
        
        const float * Pointer() const;
        
        float x;
        float y;
    };
    
    
    
    class Vector3
    {
    public:
        Vector3();
        Vector3(float x, float y, float z);
        
        void Normalize();
        Vector3 Normalized() const;
        Vector3 Cross(const Vector3 &rVector) const;
        float Dot(const Vector3 &rVector) const;
        
        Vector3 operator-(const Vector3 &rVector) const;
        
        const float * Pointer() const;
        
        float x;
        float y;
        float z;
    };
    
    
    
    class Vector4
    {
    public:
        Vector4();
        Vector4(float x, float y, float z, float w);
        
        Vector4 operator-(const Vector4 &rVector) const;
        
        const float * Pointer() const;
        
        float x;
        float y;
        float z;
        float w;
    };
}
