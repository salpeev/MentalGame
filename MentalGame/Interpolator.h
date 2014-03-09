//
//  Interpolator.h
//  MentalGame
//
//  Created by Sergey Alpeev on 07.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Quaternion.h"



namespace Renderer {
    
    class Interpolator {
    public:
        static float LERP(float start, float end, float k);
        static float QuadraticEaseIn(float start, float end, float k);
//        static float QuadraticEaseOut(float start, float end, float k);
//        static float QuadraticEaseInOut(float start, float end, float k);
        static Quaternion LERP(Quaternion &rStart, Quaternion &rEnd, float k);
        static Quaternion SLERP(Quaternion &rStart, Quaternion &rEnd, float k);
    };
}
