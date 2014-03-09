//
//  Animation.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Animation.h"
#include "Interpolator.h"
#include "GLLogger.h"



namespace Renderer {
    
    Animation::Animation(float duration, ANIMATION_CURVE curve): m_duration(duration), m_curve(curve), m_elapsedTime(0.0f) {
        
    }
    
    bool Animation::IsFinished() const {
        bool finished = (m_elapsedTime == m_duration);
        return finished;
    }
    
    float Animation::Phase() const {
        float phase = 0.0f;
        float completion = m_elapsedTime / m_duration;
        
        switch (m_curve) {
            case ANIMATION_CURVE_LINEAR: {
                phase = Interpolator::LERP(0.0f, 1.0f, completion);
                break;
            }
            case ANIMATION_CURVE_EASE_IN: {
                phase = Interpolator::QuadraticEaseIn(0.0f, 1.0f, completion);
                break;
            }
//            case ANIMATION_CURVE_EASE_OUT: {
//                phase = Interpolator::QuadraticEaseOut(0.0f, 1.0f, completion);
//                break;
//            }
//            case ANIMATION_CURVE_EASE_IN_OUT: {
//                phase = Interpolator::QuadraticEaseInOut(0.0f, 1.0f, completion);
//                break;
//            }
        }
        
        Log("COMPLETION: %f     PHASE: %f", completion, phase);
        
        return phase;
    }
    
    void Animation::Update(float interval) {
        m_elapsedTime += interval;
        
        if (m_elapsedTime >= m_duration) {
            m_elapsedTime = m_duration;
        }
    }
    
#pragma mark - Protected Methods
    
    void Animation::SetAnimationDelegate(AnimationDelegate *pAnimationDelegate) {
        m_animationDelegate = pAnimationDelegate;
    }
    
    AnimationDelegate * Animation::GetAnimationDelegate() const {
        return m_animationDelegate;
    }
}