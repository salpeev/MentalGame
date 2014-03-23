//
//  PositionAnimation.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "MoveToAnimation.h"




namespace Renderer {
    
    MoveToAnimation::MoveToAnimation(PositionModelviewModifier *pModelviewModifier, const Point &rPosition, float duration, ANIMATION_CURVE curve): Animation(duration, curve), m_modelviewModifier(pModelviewModifier), m_endPosition(rPosition) {
        m_startPosition = m_modelviewModifier->GetPosition();
    }
    
    MoveToAnimation::~MoveToAnimation() {
        
    }
    
#pragma mark - Public Methods
    
    void MoveToAnimation::Update(float interval) {
        Animation::Update(interval);
        
        Vector3 vector = m_endPosition - m_startPosition;
        float phase = Phase();
        
        Point intermediatePosition;
        intermediatePosition.x = m_startPosition.x + phase * vector.x;
        intermediatePosition.y = m_startPosition.y + phase * vector.y;
        intermediatePosition.z = m_startPosition.z + phase * vector.z;
        
        m_modelviewModifier->SetPosition(intermediatePosition);
    }
}