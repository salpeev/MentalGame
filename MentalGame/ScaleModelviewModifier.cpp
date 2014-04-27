//
//  ScaleModelviewModifier.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 27.04.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ScaleModelviewModifier.h"



namespace Renderer {
    
    ScaleModelviewModifier::ScaleModelviewModifier(): m_scale(1.0f) {
        
    }
    
    ScaleModelviewModifier::ScaleModelviewModifier(ModelviewModifier *pPrevModifier): ModelviewModifier(pPrevModifier), m_scale(1.0f) {
        
    }
    
    void ScaleModelviewModifier::SetScale(float scale) {
        m_scale = scale;
    }
    
    float ScaleModelviewModifier::GetScale() const {
        return m_scale;
    }
    
    Matrix4 ScaleModelviewModifier::GetModelviewMatrix() const {
        if (!m_prevModifier) {
            return Matrix4::DoScale(m_scale);
        }
        
        Matrix4 prevMatrix = m_prevModifier->GetModelviewMatrix();
        Matrix4 newMatrix = prevMatrix.Scale(m_scale);
        return newMatrix;
    }
}