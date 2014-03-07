//
//  Animation.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Animation.h"



namespace Renderer {
    
    Animation::Animation(float duration, ANIMATION_CURVE curve): m_duration(duration), m_curve(curve), m_elapsedTime(0.0f) {
        
    }
    
    bool Animation::IsFinished() const {
        bool finished = (m_elapsedTime == m_duration);
        return finished;
    }
    
    float Animation::Phase() const {
        float phase = m_elapsedTime / m_duration;
        return phase;
    }
    
    void Animation::Update(float interval) {
        m_elapsedTime += interval;
        
        if (m_elapsedTime >= m_duration) {
            m_elapsedTime = m_duration;
        }
    }
}