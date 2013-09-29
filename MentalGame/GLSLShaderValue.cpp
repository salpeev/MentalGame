//
//  GLSLShaderValue.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLShaderValue.h"



namespace GLRenderer
{
    GLSLShaderValue::GLSLShaderValue(GLchar *name, GLenum type, GLint size, GLint location): m_type(type), m_size(size), m_location(location)
    {
        p_name = new string(name);
    }
    
    GLSLShaderValue::~GLSLShaderValue()
    {
        delete p_name;
    }
    
    string *GLSLShaderValue::GetName() const
    {
        return p_name;
    }
    
    GLenum GLSLShaderValue::GetType() const
    {
        return m_type;
    }
    
    GLint GLSLShaderValue::GetSize() const
    {
        return m_size;
    }
    
    GLint GLSLShaderValue::GetLocation() const
    {
        return m_location;
    }
}