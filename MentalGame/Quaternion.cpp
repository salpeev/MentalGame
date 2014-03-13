//
//  Quaternion.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Quaternion.h"



namespace Renderer {
    
    Quaternion::Quaternion(): x(0.0f), y(0.0f), z(0.0f), w(1.0f) {
        
    }
    
    Quaternion::Quaternion(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {
        
    }
    
    Quaternion Quaternion::Scaled(float scale) const {
        Quaternion result(x * scale, y * scale, z * scale, w * scale);
        return result;
    }
    
    Quaternion Quaternion::Rotated(const Quaternion &rQuaternion) const {
        Quaternion quaternion;
        
        quaternion.w = w * rQuaternion.w - x * rQuaternion.x - y * rQuaternion.y - z * rQuaternion.z;
        quaternion.x = w * rQuaternion.x + x * rQuaternion.w + y * rQuaternion.z - z * rQuaternion.y;
        quaternion.y = w * rQuaternion.y + y * rQuaternion.w + z * rQuaternion.x - x * rQuaternion.z;
        quaternion.z = w * rQuaternion.z + z * rQuaternion.w + x * rQuaternion.y - y * rQuaternion.x;
        quaternion.Normalize();
        
        return quaternion;
    }
    
    float Quaternion::InnerProduct(const Quaternion &rQuaternion) const {
        float dot = x * rQuaternion.x + y * rQuaternion.y + z * rQuaternion.z + w * rQuaternion.w;
        return dot;
    }
    
    Quaternion Quaternion::operator+(const Quaternion &rQuaternion) const {
        Quaternion result(x + rQuaternion.x, y + rQuaternion.y, z + rQuaternion.z, w + rQuaternion.w);
        return result;
    }
    
    float Quaternion::Norm() const {
        float norm = InnerProduct(*this);
        return norm;
    }
    
    float Quaternion::Magnitude() const {
        float norm = Norm();
        float magnitude = sqrtf(norm);
        return magnitude;
    }
    
    void Quaternion::Normalize() {
        float scale = 1.0f / Magnitude();
        *this = Scaled(scale);
    }
    
    Matrix3 Quaternion::ToMatrix3() const {
        // TODO: Probably quaternion should be normalized http://stackoverflow.com/questions/1556260/convert-quaternion-rotation-to-rotation-matrix
        Matrix3 matrix;
        matrix.x.x = 1.0f - 2.0f * (y * y + z * z);
        matrix.x.y = 2.0f * (x * y + w * z);
        matrix.x.z = 2.0f * (x * z - y * w);
        matrix.y.x = 2.0f * (x * y - z * w);
        matrix.y.y = 1.0f - 2.0f * (x * x + z * z);
        matrix.y.z = 2.0f * (y * z + x * w);
        matrix.z.x = 2.0f * (y * w + x * z);
        matrix.z.y = 2.0f * (y * z - x * w);
        matrix.z.z = 1.0f - 2.0f * (x * x + y * y);
        return matrix;
    }
    
    Quaternion Quaternion::operator-(const Quaternion &rQuaternion) const {
        Quaternion result(x - rQuaternion.x, y - rQuaternion.y, z - rQuaternion.z, w - rQuaternion.w);
        return result;
    }
    
    Quaternion Quaternion::CreateFromVectors(const Vector3 &rVector0, const Vector3 &rVector1) {
        Vector3 vector0 = rVector0.Normalized();
        Vector3 vector1 = rVector1.Normalized();
        
        // TODO: This function numerically instable when rVector0 equal to -rVector1. Check could be added. Game Programming Gems page 215
        Vector3 cross = vector0.Cross(vector1);
        float dot = vector0.Dot(vector1);
        float s = sqrtf((1.0f + dot) * 2.0f);
        
        Quaternion quaternion;
        quaternion.x = cross.x / s;
        quaternion.y = cross.y / s;
        quaternion.z = cross.z / s;
        quaternion.w = s / 2.0f;
        return quaternion;
    }
    
    Quaternion Quaternion::CreateFromAxisAngle(const Vector3 &rAxis, float radians) {
        Vector3 axis = rAxis.Normalized();
        
        Quaternion quaternion;
        quaternion.w = cosf(radians / 2.0f);
        quaternion.x = quaternion.y = quaternion.z = sinf(radians / 2.0f);
        quaternion.x *= axis.x;
        quaternion.y *= axis.y;
        quaternion.z *= axis.z;
        return quaternion;
    }
}
