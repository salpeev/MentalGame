//
//  RotateToQuaternionAnimation.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RotateToQuaternionAnimation.h"
#include "Interpolator.h"



namespace Renderer {
    
    RotateToQuaternionAnimation::RotateToQuaternionAnimation(const Quaternion &rQuaternion, float duration, ANIMATION_CURVE curve): Animation(duration, curve), m_endQuaternion(rQuaternion) {
        
    }
    
    RotateToQuaternionAnimation::~RotateToQuaternionAnimation() {
        
    }
    
#pragma mark - Public Methods
    
    void RotateToQuaternionAnimation::Update(float interval) {
        Animation::Update(interval);
        
        float phase = Phase();
        Quaternion intermediateQuaternion = Interpolator::SLERP(m_startQuaternion, m_endQuaternion, phase);
        
        GetAnimationDelegate()->SetQuaternion(intermediateQuaternion);
    }
    
#pragma mark - Protected Methods
    
    void RotateToQuaternionAnimation::SetAnimationDelegate(AnimationDelegate *pAnimationDelegate) {
        Animation::SetAnimationDelegate(pAnimationDelegate);
        
        m_startQuaternion = pAnimationDelegate->GetQuaternion();
    }
}
