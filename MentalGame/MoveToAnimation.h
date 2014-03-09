//
//  PositionAnimation.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Animation.h"



namespace Renderer {
    
    class MoveToAnimation: public Animation {
    public:
        MoveToAnimation(const Point &rPosition, float duration, ANIMATION_CURVE curve);
        ~MoveToAnimation();
        
        void Update(float interval);
        
    protected:
        void SetAnimationDelegate(AnimationDelegate *pAnimationDelegate);
        
    private:
        Point m_startPosition;
        Point m_endPosition;
    };
}
