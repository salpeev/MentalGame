//
//  RotateByQuaternionAnimation.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RotateByQuaternionAnimation.h"
#include "Interpolator.h"



namespace Renderer {
    
    RotateByQuaternionAnimation::RotateByQuaternionAnimation(QuaternionModelviewModifier *pModelviewModifier, const Quaternion &rQuaternion, float duration, ANIMATION_CURVE curve): Animation(duration, curve), m_modelviewModifier(pModelviewModifier), m_endQuaternion(rQuaternion) {
        m_startQuaternion = m_modelviewModifier->GetQuaternion();
    }
    
    RotateByQuaternionAnimation::~RotateByQuaternionAnimation() {
        
    }
    
#pragma mark - Public Methods
    
    void RotateByQuaternionAnimation::Update(float interval) {
        Animation::Update(interval);
        
        float phase = Phase();
        Quaternion intermediateQuaternion = Interpolator::SLERP(m_startQuaternion, m_endQuaternion, phase);
        
        m_modelviewModifier->SetQuaternion(intermediateQuaternion);
    }
}
