//
//  Drawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Drawing.h"



namespace Renderer {
    
    Drawing::Drawing() {
        
    }
    
    Drawing::Drawing(GLSLDrawRequest *pDrawRequest) {
        
    }
    
    Drawing::~Drawing() {
        
    }
    
#pragma mark - Protected Methods
    
    void Drawing::SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer) {
        
    }
    
    void Drawing::SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer) {
        
    }
    
    GLSLAttributeInitializer * Drawing::GetAttributeInitializer() const {
        return m_attributeInitializer;
    }
    
    GLSLUniformInitializer * Drawing::GetUniformInitializer() const {
        return m_uniformInitializer;
    }
}