//
//  GLSLVertex.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertex.h"
#include "GLConstants.h"



namespace GLRenderer
{
    GLSLVertex1P::GLSLVertex1P(): GLSLVertex1P(GLPoint())
    {
        
    }
    
    GLSLVertex1P::GLSLVertex1P(GLPoint position): m_position(position)
    {
        
    }
    
    void GLSLVertex1P::SetPosition(GLPoint position)
    {
        m_position = position;
    }
    
    GLPoint GLSLVertex1P::GetPosition() const
    {
        return m_position;
    }
    
    
    
    GLSLVertex1C::GLSLVertex1C(): GLSLVertex1C(GLColor())
    {
        
    }
    
    GLSLVertex1C::GLSLVertex1C(GLColor color): m_color(color)
    {
        
    }
    
    void GLSLVertex1C::SetColor(GLColor color)
    {
        m_color = color;
    }
    
    GLColor GLSLVertex1C::GetColor() const
    {
        return m_color;
    }
    
    
    
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

