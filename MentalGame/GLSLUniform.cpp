//
//  GLSLUniform.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLUniform.h"



namespace Renderer
{
    GLSLUniform::GLSLUniform(GLchar *name, GLenum type, GLint size, GLint location): m_name(name), m_type(type), m_size(size), m_location(location)
    {
        
    }
    
    GLSLUniform::~GLSLUniform()
    {
        delete m_name;
    }
    
    GLchar * GLSLUniform::GetName() const
    {
        return m_name;
    }
    
    GLenum GLSLUniform::GetType() const
    {
        return m_type;
    }
    
    GLint GLSLUniform::GetSize() const
    {
        return m_size;
    }
    
    GLint GLSLUniform::GetLocation() const
    {
        return m_location;
    }
}