//
//  RotateToQuaternionAnimation.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Animation.h"



namespace Renderer {
    
    class RotateToQuaternionAnimation: public Animation {
    public:
        RotateToQuaternionAnimation(const Quaternion &rQuaternion, float duration, ANIMATION_CURVE curve);
        ~RotateToQuaternionAnimation();
        
        void Update(float interval);
        
    protected:
        void SetAnimationDelegate(AnimationDelegate *pAnimationDelegate);
        
    private:
        Quaternion m_startQuaternion;
        Quaternion m_endQuaternion;
    };
}