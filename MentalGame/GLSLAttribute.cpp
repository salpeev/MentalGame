//
//  GLSLAttribute.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLAttribute.h"



namespace Renderer
{
    GLSLAttribute::GLSLAttribute(GLchar *name, GLenum type, GLint size, GLint location): m_name(name), m_type(type), m_size(size), m_location(location)
    {
        
    }
    
    GLSLAttribute::~GLSLAttribute()
    {
        delete m_name;
    }
    
    GLchar * GLSLAttribute::GetName() const
    {
        return m_name;
    }
    
    GLenum GLSLAttribute::GetType() const
    {
        return m_type;
    }
    
    GLint GLSLAttribute::GetSize() const
    {
        return m_size;
    }
    
    GLint GLSLAttribute::GetLocation() const
    {
        return m_location;
    }
}