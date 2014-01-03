//
//  GLSLAttribute.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLAttribute.h"
#include "GLConstants.h"
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
        
        bool enabled = (arrayEnabled == GLSL_TRUE);
        return enabled;
    }
    
    void GLSLAttribute::SetBufferPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, GLuint offset) const
    {
        
    }
    
    void GLSLAttribute::SetDataPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, const GLvoid *pData) const
    {
        
    }
    
    void GLSLAttribute::Set1f(GLfloat value) const
    {
        
    }
    
    void GLSLAttribute::Set2f(GLfloat value0, GLfloat value1) const
    {
        
    }
    
    void GLSLAttribute::Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const
    {
        
    }
    
    void GLSLAttribute::Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const
    {
        
    }
    
    void GLSLAttribute::Set1fv(const GLfloat *pValue) const
    {
        
    }
    
    void GLSLAttribute::Set2fv(const GLfloat *pValue) const
    {
        
    }
    
    void GLSLAttribute::Set3fv(const GLfloat *pValue) const
    {
        
    }
    
    void GLSLAttribute::Set4fv(const GLfloat *pValue) const
    {
        
    }
    
    GLfloat GLSLAttribute::Get1f() const
    {
        
    }
    
    void GLSLAttribute::Get2f(GLfloat *pValue0, GLfloat *pValue1) const
    {
        
    }
    
    void GLSLAttribute::Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const
    {
        
    }
    
    void GLSLAttribute::Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const
    {
        
    }
    
    void GLSLAttribute::Get1fv(GLfloat *pValue) const
    {
        
    }
    
    void GLSLAttribute::Get2fv(GLfloat *pValue) const
    {
        
    }
    
    void GLSLAttribute::Get3fv(GLfloat *pValue) const
    {
        
    }
    
    void GLSLAttribute::Get4fv(GLfloat *pValue) const
    {
        
    }
    
}