//
//  AnimationDelegate.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 08.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "AnimationDelegate.h"



namespace Renderer {
    
    AnimationDelegate::~AnimationDelegate() {
        
    }
    
    Point AnimationDelegate::GetPosition() const {
        return Point();
    }
    
    float AnimationDelegate::GetXRotation() const {
        return 0.0f;
    }
    
    float AnimationDelegate::GetYRotation() const {
        return 0.0f;
    }
    
    float AnimationDelegate::GetZRotation() const {
        return 0.0f;
    }
    
    Quaternion AnimationDelegate::GetQuaternion() const {
        return Quaternion();
    }
    
    
    void AnimationDelegate::SetPosition(const Point &rPosition) {
        
    }
    
    void AnimationDelegate::SetXRotation(float angle) {
        
    }
    
    void AnimationDelegate::SetYRotation(float angle) {
        
    }
    
    void AnimationDelegate::SetZRotation(float angle) {
        
    }
    
    void AnimationDelegate::SetQuaternion(const Quaternion &rQuaternion) {
        
    }
    
}