//
//  Matrix.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Vector.h"



namespace Renderer {
    
    class Matrix2 {
    public:
        
        const float * Pointer() const;
        
        Vector2 x;
        Vector2 y;
    };
    
    
    
    class Matrix3 {
    public:
        const float * Pointer() const;
        
        Vector3 x;
        Vector3 y;
        Vector3 z;
    };
    
    
    
    class Matrix4 {
    public:
        Matrix4();
        
        Matrix4 operator * (const Matrix4 &rMatrix) const;
        
        Matrix4 & Translate(float xTranslation, float yTranslation, float zTranslation);
        Matrix4 & RotateX(float radians);
        Matrix4 & RotateY(float radians);
        Matrix4 & RotateZ(float radians);
        
        const float * Pointer() const;
        
        // TODO: There is another way to create frustum
        static Matrix4 Frustum(float left, float right, float bottom, float top, float near, float far);
        static Matrix4 Translation(float xTranslation, float yTranslation, float zTranslation);
        static Matrix4 RotationX(float radians);
        static Matrix4 RotationY(float radians);
        static Matrix4 RotationZ(float radians);
        
        Vector4 x;
        Vector4 y;
        Vector4 z;
        Vector4 w;
    };
}
