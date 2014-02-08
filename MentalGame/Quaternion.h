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
        float Dot(const Quaternion &rQuaternion) const;
        
        Quaternion operator+(const Quaternion &rQuaternion) const;
        Quaternion operator-(const Quaternion &rQuaternion) const;
        
        float x;
        float y;
        float z;
        float w;
    };
}
