//
//  GLSLAttribute.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLAttribute.h"
#include "GLLogger.h"



namespace GLRenderer
{
    GLSLAttribute::GLSLAttribute(GLSLProgram *pProgram, GLchar *name, GLenum type, GLint size, GLint location): GLSLShaderValue(pProgram, name, type, size, location)
    {
        
    }
    
    void GLSLAttribute::EnableArray() const
    {
        if (!IsArrayEnabled())
        {
            glEnableVertexAttribArray(m_location);
            CheckError();
        }
        
    }
    
    void GLSLAttribute::DisableArray() const
    {
        if (IsArrayEnabled())
        {
            glDisableVertexAttribArray(m_location);
            CheckError();
        }
    }
    
    bool GLSLAttribute::IsArrayEnabled() const
    {
        GLint arrayEnabled;
        glGetVertexAttribiv(m_location, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &arrayEnabled);
        CheckError();
        
        bool enabled = (arrayEnabled == GL_TRUE);
        return enabled;
    }
}