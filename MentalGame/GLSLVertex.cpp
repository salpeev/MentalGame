//
//  GLSLVertex.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertex.h"



namespace GLRenderer
{
    GLSLVertex1P1C::GLSLVertex1P1C(): GLSLVertex1P1C(GLPoint(), GLColor())
    {
        
    }
    
    GLSLVertex1P1C::GLSLVertex1P1C(GLPoint position, GLColor color): m_position(position), m_color(color)
    {
        
    }
    
    void GLSLVertex1P1C::SetPosition(GLPoint position)
    {
        m_position = position;
    }
    
    void GLSLVertex1P1C::SetColor(GLColor color)
    {
        m_color = color;
    }
    
    GLPoint GLSLVertex1P1C::GetPosition() const
    {
        return m_position;
    }
    
    GLColor GLSLVertex1P1C::GetColor() const
    {
        return m_color;
    }
}