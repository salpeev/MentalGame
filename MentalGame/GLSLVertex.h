//
//  GLSLVertex.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLPoint.h"
#include "GLColor.h"



namespace GLRenderer
{
    class GLSLVertex1P1C
    {
    public:
        GLSLVertex1P1C();
        GLSLVertex1P1C(GLPoint position, GLColor color);
        
        void SetPosition(GLPoint position);
        void SetColor(GLColor color);
        
        GLPoint GetPosition() const;
        GLColor GetColor() const;
        
    private:
        GLPoint m_position;
        GLColor m_color;
    };
}
