//
//  QuaternionModelviewModifier.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "QuaternionModelviewModifier.h"
#include "Logger.h"



namespace Renderer {
    
    QuaternionModelviewModifier::QuaternionModelviewModifier() {
        
    }
    
    QuaternionModelviewModifier::QuaternionModelviewModifier(ModelviewModifier *pPrevModifier): ModelviewModifier(pPrevModifier) {
        
    }
    
    void QuaternionModelviewModifier::SetQuaternion(const Quaternion &rQuaternion) {
        m_quaternion = rQuaternion;
    }
    
    Quaternion QuaternionModelviewModifier::GetQuaternion() const {
        return m_quaternion;
    }
    
    Matrix4 QuaternionModelviewModifier::GetModelviewMatrix() const {
        if (!m_prevModifier) {
            return m_quaternion.ToMatrix4();
        }
        
        Matrix4 prevMatrix = m_prevModifier->GetModelviewMatrix();
        Matrix4 curMatrix = m_quaternion.ToMatrix4();
        Matrix4 newMatrix = curMatrix * prevMatrix;
        return newMatrix;
    }
}
