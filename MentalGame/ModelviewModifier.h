//
//  ModelviewModifier.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Matrix.h"



namespace Renderer {
    
    class ModelviewModifier {
    public:
        ModelviewModifier();
        ModelviewModifier(ModelviewModifier *pPrevModifier);
        virtual ~ModelviewModifier();
        
        virtual Matrix4 GetModelviewMatrix() const = 0;
        
    protected:
        ModelviewModifier *m_prevModifier;
    };
}
