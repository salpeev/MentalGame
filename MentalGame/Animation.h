//
//  Animation.h
//  MentalGame
//
//  Created by Sergey Alpeev on 01.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingComponent.h"



enum ANIMATION_CURVE {
    ANIMATION_CURVE_LINEAR,
    ANIMATION_CURVE_EASE_IN,
    ANIMATION_CURVE_EASE_OUT,
    ANIMATION_CURVE_EASE_IN_OUT
};



namespace Renderer {
    
    class Animation {
    public:
        Animation(float duration, ANIMATION_CURVE curve);
        
        bool IsFinished() const;
        float Phase() const;
        
        virtual void Update(float interval);
        
    private:
        float m_duration;
        float m_elapsedTime;
        ANIMATION_CURVE m_curve;
    };
}
