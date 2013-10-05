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
    
    GLint GLSLVertex1P::GetSizeAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return GLSL_FLOATS_3;
            default: return 0;
        }
    }
    
    GLint GLSLVertex1P::GetMembersCount() const
    {
        return 1;
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
    
    GLint GLSLVertex1C::GetSizeAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return GLSL_FLOATS_4;
            default: return 0;
        }
    }
    
    GLint GLSLVertex1C::GetMembersCount() const
    {
        return 1;
    }
    
    
    
    GLSLVertex1P1C::GLSLVertex1P1C(): GLSLVertex1P1C(GLPoint(), GLColor())
    {
        
    }
    
    GLSLVertex1P1C::GLSLVertex1P1C(GLPoint position, GLColor color): m_position(GLSLVertex1P(position)), m_color(GLSLVertex1C(color))
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
        return m_position.GetPosition();
    }
    
    GLColor GLSLVertex1P1C::GetColor() const
    {
        return m_color.GetColor();
    }
    
    GLint GLSLVertex1P1C::GetSizeAtIndex(GLint index) const
    {
        GLint currentFirstIndex = 0;
        GLint nextElementFirstIndex = currentFirstIndex + m_position.GetMembersCount();
        
        if (index < nextElementFirstIndex) {
            GLint convertedIndex = index - currentFirstIndex;
            return m_position.GetSizeAtIndex(convertedIndex);
        }
        
        currentFirstIndex = nextElementFirstIndex;
        nextElementFirstIndex = currentFirstIndex + m_color.GetMembersCount();
        
        if (index < nextElementFirstIndex) {
            GLint convertedIndex = index - currentFirstIndex;
            return m_color.GetSizeAtIndex(convertedIndex);
        }
        
        return GLSL_FLOATS_0;
    }
    
    GLint GLSLVertex1P1C::GetMembersCount() const
    {
        GLint membersCount = m_position.GetMembersCount() + m_color.GetMembersCount();
        return membersCount;
    }
}

