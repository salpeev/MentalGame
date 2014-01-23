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



namespace Renderer
{
    class GLSLVertex1P
    {
    public:
        GLSLVertex1P();
        GLSLVertex1P(GLPoint position);
        
        GLPoint m_position;
    };
    
    
    
    class GLSLVertex1C
    {
    public:
        GLSLVertex1C();
        GLSLVertex1C(GLColor color);
        
        GLColor m_color;
    };
    
    
    
    class GLSLVertex1P1C
    {
    public:
        GLSLVertex1P1C();
        GLSLVertex1P1C(GLPoint position, GLColor color);
        
        GLPoint m_position;
        GLColor m_color;
    };
}
