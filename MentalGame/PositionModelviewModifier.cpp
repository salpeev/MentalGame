//
//  PositionModelviewModifier.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "PositionModelviewModifier.h"
#include "Logger.h"



namespace Renderer {
    
    PositionModelviewModifier::PositionModelviewModifier() {
        
    }
    
    PositionModelviewModifier::PositionModelviewModifier(ModelviewModifier *pPrevModifier): ModelviewModifier(pPrevModifier) {
        
    }
        
    void PositionModelviewModifier::SetPosition(const Point &rPosition) {
        m_position = rPosition;
    }
    
    Point PositionModelviewModifier::GetPosition() const {
        return m_position;
    }
    
    Matrix4 PositionModelviewModifier::GetModelviewMatrix() const {
        if (!m_prevModifier) {
            return Matrix4::Translation(m_position.x, m_position.y, m_position.z);
        }
        
        Matrix4 prevMatrix = m_prevModifier->GetModelviewMatrix();
        prevMatrix.MakeTranslation(m_position.x, m_position.y, m_position.z);
        return prevMatrix;
    }
}