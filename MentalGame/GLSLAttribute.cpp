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
    
#pragma mark - Public Methods
    
    void GLSLAttribute::SetBufferPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, GLsizei offset) const
    {
        EnableArray();
        
        glVertexAttribPointer(GetLocation(), size, type, normalized, stride, (GLvoid *)offset);
        CheckError();
    }
    
    void GLSLAttribute::SetDataPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, const GLvoid *pData) const
    {
        EnableArray();
        
        glVertexAttribPointer(GetLocation(), size, type, normalized, stride, pData);
        CheckError();
    }
    
    void GLSLAttribute::Set1f(GLfloat value) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib1f(GetLocation(), value);
        CheckError();
    }
    
    void GLSLAttribute::Set2f(GLfloat value0, GLfloat value1) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib2f(GetLocation(), value0, value1);
        CheckError();
    }
    
    void GLSLAttribute::Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib3f(GetLocation(), value0, value1, value2);
        CheckError();
    }
    
    void GLSLAttribute::Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib4f(GetLocation(), value0, value1, value2, value3);
        CheckError();
    }
    
    void GLSLAttribute::Set1fv(const GLfloat *pValue) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib1fv(GetLocation(), pValue);
        CheckError();
    }
    
    void GLSLAttribute::Set2fv(const GLfloat *pValues) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib2fv(GetLocation(), pValues);
        CheckError();
    }
    
    void GLSLAttribute::Set3fv(const GLfloat *pValues) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib3fv(GetLocation(), pValues);
        CheckError();
    }
    
    void GLSLAttribute::Set4fv(const GLfloat *pValues) const
    {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib4fv(GetLocation(), pValues);
        CheckError();
    }
    
    GLfloat GLSLAttribute::Get1f() const
    {
        // TODO: Should be tested
        GLfloat *pValue = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValue);
        CheckError();
        
        GLfloat value = *pValue;
        return value;
    }
    
    void GLSLAttribute::Get2f(GLfloat *pValue0, GLfloat *pValue1) const
    {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
    }
    
    void GLSLAttribute::Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const
    {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
    }
    
    void GLSLAttribute::Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const
    {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
        *pValue3 = pValues[3];
    }
    
    void GLSLAttribute::Get1fv(GLfloat *pValue) const
    {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValue);
        CheckError();
    }
    
    void GLSLAttribute::Get2fv(GLfloat *pValues) const
    {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
    }
    
    void GLSLAttribute::Get3fv(GLfloat *pValues) const
    {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
    }
    
    void GLSLAttribute::Get4fv(GLfloat *pValues) const
    {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
    }
    
#pragma mark - Private Methods
    
    void GLSLAttribute::EnableArray() const
    {
        if (!IsArrayEnabled())
        {
            glEnableVertexAttribArray(GetLocation());
            CheckError();
        }
        
    }
    
    void GLSLAttribute::DisableArray() const
    {
        if (IsArrayEnabled())
        {
            glDisableVertexAttribArray(GetLocation());
            CheckError();
        }
    }
    
    bool GLSLAttribute::IsArrayEnabled() const
    {
        GLint arrayEnabled;
        glGetVertexAttribiv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_ARRAY_ENABLED, &arrayEnabled);
        CheckError();
        
        bool enabled = (arrayEnabled == GLSL_TRUE);
        return enabled;
    }
}