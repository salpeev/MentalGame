//
//  QuaternionModelviewModifier.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "ModelviewModifier.h"
#include "Quaternion.h"



namespace Renderer {
    
    class QuaternionModelviewModifier: public ModelviewModifier {
    public:
        QuaternionModelviewModifier();
        QuaternionModelviewModifier(ModelviewModifier *pPrevModifier);
        
        void SetQuaternion(const Quaternion &rQuaternion);
        Quaternion GetQuaternion() const;
        
        Matrix4 GetModelviewMatrix() const;
        
    private:
        Quaternion m_quaternion;
    };
}
