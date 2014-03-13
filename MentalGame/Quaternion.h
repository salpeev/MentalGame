//
//  Quaternion.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Matrix.h"



namespace Renderer {
    
    class Quaternion {
    public:
        Quaternion();
        Quaternion(float x, float y, float z, float w);
        
        Quaternion Scaled(float scale) const;
        Quaternion Rotated(const Quaternion &rQuaternion) const;
        float InnerProduct(const Quaternion &rQuaternion) const; // Dot
        float Norm() const;
        float Magnitude() const;
        void Normalize();
        
        Matrix3 ToMatrix3() const;
        
        Quaternion operator+(const Quaternion &rQuaternion) const;
        Quaternion operator-(const Quaternion &rQuaternion) const;
        
        static Quaternion CreateFromVectors(const Vector3 &rVector0, const Vector3 &rVector1);
        static Quaternion CreateFromAxisAngle(const Vector3 &rAxis, float radians);
        
        float x;
        float y;
        float z;
        float w;
    };
}
