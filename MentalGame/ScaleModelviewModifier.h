//
//  ScaleModelviewModifier.h
//  MentalGame
//
//  Created by Sergey Alpeev on 27.04.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "ModelviewModifier.h"



namespace Renderer {
    
    class ScaleModelviewModifier: public ModelviewModifier {
    public:
        ScaleModelviewModifier();
        ScaleModelviewModifier(ModelviewModifier *pPrevModifier);
        
        void SetScale(float scale);
        float GetScale() const;
        
        Matrix4 GetModelviewMatrix() const;
    private:
        float m_scale;
    };
}
