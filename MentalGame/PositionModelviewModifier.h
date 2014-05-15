//
//  PositionModelviewModifier.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "ModelviewModifier.h"



namespace Renderer {
    
    class PositionModelviewModifier: public ModelviewModifier {
    public:
        PositionModelviewModifier();
        PositionModelviewModifier(ModelviewModifier *pPrevModifier);
        
        void SetPosition(const Point3 &rPosition);
        Point3 GetPosition() const;
        
        Matrix4 GetModelviewMatrix() const;
        
    private:
        Point3 m_position;
    };
}
