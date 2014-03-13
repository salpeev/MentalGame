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
        Matrix2();
        
        Matrix2 operator*(const Matrix2 &rMatrix) const;
        
        float Determinant() const;
        bool Inverted(Matrix2 *pResultMatrix) const;
        
        const float * Pointer() const;
        
        Vector2 x;
        Vector2 y;
    };
    
    
    
    class Matrix3 {
    public:
        Matrix3();
        
        Matrix3 operator*(const Matrix3 &rMatrix) const;
        
        float Determinant() const;
        bool Inverted(Matrix3 *pResultMatrix) const;
        Matrix3 Transposed() const;
        
        const float * Pointer() const;
        
        Vector3 x;
        Vector3 y;
        Vector3 z;
    };
    
    
    
    class Matrix4 {
    public:
        Matrix4();
        Matrix4(const Matrix3 &rMatrix);
        
        Matrix4 operator*(const Matrix4 &rMatrix) const;
        
        Matrix4 & MakeTranslation(float xTranslation, float yTranslation, float zTranslation);
        Matrix4 & Translate(float xTranslation, float yTranslation, float zTranslation);
        Matrix4 & RotateX(float radians);
        Matrix4 & RotateY(float radians);
        Matrix4 & RotateZ(float radians);
        Matrix4 & Transpose();
        
        Matrix4 Transposed() const;
        float Determinant() const;
        bool Inverted(Matrix4 *pResultMatrix) const;
        
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
