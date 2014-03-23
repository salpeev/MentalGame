//
//  ModelviewModifier.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ModelviewModifier.h"



namespace Renderer {
    
    ModelviewModifier::ModelviewModifier(): m_prevModifier(nullptr) {
        
    }
    
    ModelviewModifier::ModelviewModifier(ModelviewModifier *pPrevModifier): m_prevModifier(pPrevModifier) {
        
    }
    
    ModelviewModifier::~ModelviewModifier() {
        delete m_prevModifier;
    }
}