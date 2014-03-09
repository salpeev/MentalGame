//
//  Interpolator.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Interpolator.h"



namespace Renderer {
    
    float Interpolator::LERP(float start, float end, float k) {
        if (k < 0.0f) {
            return start;
        }
        
        if (k > 1.0f) {
            return end;
        }
        
        float result = (1.0f - k) * start + k * end;
        return result;
    }
    
    float Interpolator::QuadraticEaseIn(float start, float end, float k) {
        float quadraticK = k * k;
        float result = LERP(start, end, quadraticK);
        return result;
    }
    
//    float Interpolator::QuadraticEaseOut(float start, float end, float k) {
//#warning Works incorrectly
//        float quadraticK = k * k;
//        float result = LERP(end, start, quadraticK);
//        return result;
//    }
//    
//    float Interpolator::QuadraticEaseInOut(float start, float end, float k) {
//#warning Works incorrectly
//        if (k < 0.0f) {
//            return start;
//        }
//        
//        if (k > 1.0f) {
//            return end;
//        }
//        
//        float middle = (start + end) / 2.0f;
//        float doubleK = 2.0f * k;
//        
//        if (doubleK <= 1.0f) {
//            float quadraticDoubleK = doubleK * doubleK;
//            float result = LERP(start, middle, quadraticDoubleK);
//            return result;
//        }
//        
//        doubleK -= 1.0f;
//        float quadraticDoubleK = doubleK * doubleK;
//        float result = LERP(middle, end, quadraticDoubleK);
//        return result;
//    }
    
    Quaternion Interpolator::LERP(Quaternion &rStart, Quaternion &rEnd, float k) {
        Quaternion result;
        result.x = LERP(rStart.x, rEnd.x, k);
        result.y = LERP(rStart.y, rEnd.y, k);
        result.z = LERP(rStart.z, rEnd.z, k);
        result.w = LERP(rStart.w, rEnd.w, k);
        return result;
    }
    
    Quaternion Interpolator::SLERP(Quaternion &rStart, Quaternion &rEnd, float k) {
        if (k < 0.0f) {
            return rStart;
        }
        
        if (k > 1.0f) {
            return rEnd;
        }
        
        float dot = rStart.Dot(rEnd);
        float theta0 = acosf(dot);
        float theta = theta0 * k;
        
        float wp = sinf((1 - k) * theta) / sinf(theta);
        float wq = sinf(k * theta) / sinf(theta);
        
        Quaternion result = rStart.Scaled(wp) + rEnd.Scaled(wq);
        return result;
    }
}
