//
//  Vector.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Vector.h"



namespace Renderer
{
#pragma mark - Vector2
    
    Vector2::Vector2(): Vector2(0.0f, 0.0f) {
        
    }
    
    Vector2::Vector2(float x, float y): x(x), y(y) {
        
    }
    
    Vector2 Vector2::operator-(const Vector2 &rVector) const {
        Vector2 vector(x - rVector.x, y - rVector.y);
        return vector;
    }
    
    const float * Vector2::Pointer() const {
        return &x;
    }
    
#pragma mark - Vector3
    
    Vector3::Vector3(): Vector3(0.0f, 0.0f, 0.0f) {
        
    }
    
    Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {
        
    }
    
    void Vector3::Normalize() {
        float scale = 1.0f / sqrtf(x * x + y * y + z * z);
        x *= scale;
        y *= scale;
        z *= scale;
    }
    
    Vector3 Vector3::Normalized() const {
        Vector3 vector(*this);
        vector.Normalize();
        return vector;
    }
    
    Vector3 Vector3::Cross(const Vector3 &rVector) const {
        float newX = y * rVector.z - z * rVector.y;
        float newY = z * rVector.x - x * rVector.z;
        float newZ = x * rVector.y - y * rVector.x;
        Vector3 vector(newX, newY, newZ);
        return vector;
    }
    
    float Vector3::Dot(const Vector3 &rVector) const {
        float dot = x * rVector.x + y * rVector.y + z * rVector.z;
        return dot;
    }
    
    Vector3 Vector3::operator-(const Vector3 &rVector) const {
        Vector3 vector(x - rVector.x, y - rVector.y, z - rVector.z);
        return vector;
    }
    
    const float * Vector3::Pointer() const {
        return &x;
    }
    
#pragma mark - Vector4
    
    Vector4::Vector4(): Vector4(0.0f, 0.0f, 0.0f, 0.0f) {
        
    }
    
    Vector4::Vector4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {
        
    }
    
    Vector4 Vector4::operator-(const Vector4 &rVector) const {
        Vector4 vector(x - rVector.x, y - rVector.y, z - rVector.z, w - rVector.w);
        return vector;
    }
    
    const float * Vector4::Pointer() const {
        return &x;
    }
    
}
