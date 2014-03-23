//
//  RotateByQuaternionAnimation.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Animation.h"
#include "QuaternionModelviewModifier.h"



namespace Renderer {
    
    class RotateByQuaternionAnimation: public Animation {
    public:
        RotateByQuaternionAnimation(QuaternionModelviewModifier *pModelviewModifier, const Quaternion &rQuaternion, float duration, ANIMATION_CURVE curve);
        ~RotateByQuaternionAnimation();
        
        void Update(float interval);
        
    protected:
        void SetAnimationDelegate(AnimationDelegate *pAnimationDelegate);
        
    private:
        QuaternionModelviewModifier *m_modelviewModifier;
        Quaternion m_startQuaternion;
        Quaternion m_endQuaternion;
    };
}