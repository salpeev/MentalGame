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
    
    float Quaternion::Dot(const Quaternion &rQuaternion) const {
        float dot = x * rQuaternion.x + y * rQuaternion.y + z * rQuaternion.z;
        return dot;
    }
    
    Quaternion Quaternion::operator+(const Quaternion &rQuaternion) const {
        Quaternion result(x + rQuaternion.x, y + rQuaternion.y, z + rQuaternion.z, w + rQuaternion.w);
        return result;
    }
    
    Quaternion Quaternion::operator-(const Quaternion &rQuaternion) const {
        Quaternion result(x - rQuaternion.x, y - rQuaternion.y, z - rQuaternion.z, w - rQuaternion.w);
        return result;
    }
}
