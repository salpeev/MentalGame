//
//  PositionAnimation.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "MoveToAnimation.h"




namespace Renderer {
    
    MoveToAnimation::MoveToAnimation(const Point &rPosition, float duration, ANIMATION_CURVE curve): Animation(duration, curve), m_endPosition(rPosition) {
        
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
        
        GetAnimationDelegate()->SetPosition(intermediatePosition);
    }
    
#pragma mark - Protected Methods
    
    void MoveToAnimation::SetAnimationDelegate(AnimationDelegate *pAnimationDelegate) {
        Animation::SetAnimationDelegate(pAnimationDelegate);
        
        m_startPosition = pAnimationDelegate->GetPosition();
    }
}