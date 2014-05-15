//
//  PositionAnimation.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Animation.h"
#include "PositionModelviewModifier.h"



namespace Renderer {
    
    class MoveToAnimation: public Animation {
    public:
        MoveToAnimation(PositionModelviewModifier *pModelviewModifier, const Point3 &rPosition, float duration, ANIMATION_CURVE curve);
        ~MoveToAnimation();
        
        void Update(float interval);
        
    private:
        PositionModelviewModifier *m_modelviewModifier;
        Point3 m_startPosition;
        Point3 m_endPosition;
    };
}
