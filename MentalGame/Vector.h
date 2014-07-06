//
//  Vector.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <cmath>
#include "Point.h"


namespace Renderer
{
    class Matrix3;
    class Matrix4;
    
    
    
    class Vector2
    {
    public:
        Vector2();
        Vector2(float x, float y);
        
        Vector2 operator+(const Vector2 &rVector) const;
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
        
        Vector3 operator-() const;
        Vector3 operator-(const Vector3 &rVector) const;
        Vector3 operator*(float scale) const;
        Vector3 operator*(const Matrix3 &rMatrix) const;
        bool operator==(const Vector3 &rVector) const;
        operator Point3() const;
        
        float Length() const;
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
        Vector4(const Vector3 &rVector);
        Vector4(const Vector3 &rVector, float w);
        Vector4(const Point3 &rPoint);
        
        Vector4 operator-() const;
        Vector4 operator-(const Vector4 &rVector) const;
        Vector4 operator*(const Matrix4 &rMatrix) const;
        
        const float * Pointer() const;
        
        float x;
        float y;
        float z;
        float w;
    };
}
