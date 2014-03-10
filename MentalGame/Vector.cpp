//
//  Vector.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Vector.h"
#include "Matrix.h"



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
    
    Vector3 Vector3::operator-() const {
        Vector3 vector(-x, -y, -z);
        return vector;
    }
    
    Vector3 Vector3::operator-(const Vector3 &rVector) const {
        Vector3 vector(x - rVector.x, y - rVector.y, z - rVector.z);
        return vector;
    }
    
    Vector3 Vector3::operator*(float scale) const {
        Vector3 vector(x * scale, y * scale, z * scale);
        return vector;
    }
    
    Vector3 Vector3::operator*(const Matrix3 &rMatrix) const {
        float newX = x * rMatrix.x.x + y * rMatrix.y.x + z * rMatrix.z.x;
        float newY = x * rMatrix.x.y + y * rMatrix.y.y + z * rMatrix.z.y;
        float newZ = x * rMatrix.x.z + y * rMatrix.y.z + z * rMatrix.z.z;
        Vector3 vector(newX, newY, newZ);
        return vector;
    }
    
    bool Vector3::operator==(const Vector3 &rVector) const {
        bool equal = (x == rVector.x) && (y == rVector.y) && (z == rVector.z);
        return equal;
    }
    
    Vector3::operator Point() const {
        Point point(x, y, z);
        return point;
    }
    
    float Vector3::Length() const {
        float length = sqrtf(x * x + y * y + z * z);
        return length;
    }
    
    const float * Vector3::Pointer() const {
        return &x;
    }
    
#pragma mark - Vector4
    
    Vector4::Vector4(): Vector4(0.0f, 0.0f, 0.0f, 0.0f) {
        
    }
    
    Vector4::Vector4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {
        
    }
    
    Vector4::Vector4(Vector3 &rVector): Vector4(rVector, 1.0f) {
        
    }
    
    Vector4::Vector4(Vector3 &rVector, float w): Vector4(rVector.x, rVector.y, rVector.z, w) {
        
    }
    
    Vector4 Vector4::operator-(const Vector4 &rVector) const {
        Vector4 vector(x - rVector.x, y - rVector.y, z - rVector.z, w - rVector.w);
        return vector;
    }
    
    Vector4 Vector4::operator*(const Matrix4 &rMatrix) const {
        float newX = x * rMatrix.x.x + y * rMatrix.y.x + z * rMatrix.z.x + w * rMatrix.w.x;
        float newY = x * rMatrix.x.y + y * rMatrix.y.y + z * rMatrix.z.y + w * rMatrix.w.y;
        float newZ = x * rMatrix.x.z + y * rMatrix.y.z + z * rMatrix.z.z + w * rMatrix.w.z;
        float newW = x * rMatrix.x.w + y * rMatrix.y.w + z * rMatrix.z.w + w * rMatrix.w.w;
        Vector4 vector(newX, newY, newZ, newW);
        return vector;
    }
    
    const float * Vector4::Pointer() const {
        return &x;
    }
    
}
