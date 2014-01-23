//
//  GLSLUniform.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLUniform.h"
#include "GLLogger.h"
#include "GLSLProgram.h"



namespace Renderer
{
#pragma mark - Public Methods
    
    GLSLUniform::GLSLUniform(GLSLProgram *pProgram, GLchar *name, GLenum type, GLint size, GLint location): GLSLShaderValue(pProgram, name, type, size, location)
    {
        
    }
    
    void GLSLUniform::Set1f(GLfloat value) const
    {
        // TODO: Should be tested
        glUniform1f(GetLocation(), value);
        CheckError();
    }
    
    void GLSLUniform::Set2f(GLfloat value0, GLfloat value1) const
    {
        // TODO: Should be tested
        glUniform2f(GetLocation(), value0, value1);
        CheckError();
    }
    
    void GLSLUniform::Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const
    {
        // TODO: Should be tested
        glUniform3f(GetLocation(), value0, value1, value2);
        CheckError();
    }
    
    void GLSLUniform::Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const
    {
        // TODO: Should be tested
        glUniform4f(GetLocation(), value0, value1, value2, value3);
        CheckError();
    }
    
    void GLSLUniform::Set1i(GLint value) const
    {
        // TODO: Should be tested
        glUniform1i(GetLocation(), value);
        CheckError();
    }
    
    void GLSLUniform::Set2i(GLint value0, GLint value1) const
    {
        // TODO: Should be tested
        glUniform2i(GetLocation(), value0, value1);
        CheckError();
    }
    
    void GLSLUniform::Set3i(GLint value0, GLint value1, GLint value2) const
    {
        // TODO: Should be tested
        glUniform3i(GetLocation(), value0, value1, value2);
        CheckError();
    }
    
    void GLSLUniform::Set4i(GLint value0, GLint value1, GLint value2, GLint value3) const
    {
        // TODO: Should be tested
        glUniform4i(GetLocation(), value0, value1, value2, value3);
        CheckError();
    }
    
    void GLSLUniform::Set1fv(const GLfloat *pValues) const
    {
        // TODO: Should be tested
        glUniform1fv(GetLocation(), GetSize(), pValues);
        CheckError();
    }
    
    void GLSLUniform::Set2fv(const GLfloat *pValues) const
    {
        // TODO: Should be tested
        glUniform2fv(GetLocation(), GetSize(), pValues);
        CheckError();
    }
    
    void GLSLUniform::Set3fv(const GLfloat *pValues) const
    {
        // TODO: Should be tested
        glUniform3fv(GetLocation(), GetSize(), pValues);
        CheckError();
    }
    
    void GLSLUniform::Set4fv(const GLfloat *pValues) const
    {
        // TODO: Should be tested
        glUniform4fv(GetLocation(), GetSize(), pValues);
        CheckError();
    }
    
    void GLSLUniform::Set1iv(const GLint *pValue) const
    {
        // TODO: Should be tested
        glUniform1iv(GetLocation(), GetSize(), pValue);
        CheckError();
    }
    
    void GLSLUniform::Set2iv(const GLint *pValues) const
    {
        // TODO: Should be tested
        glUniform2iv(GetLocation(), GetSize(), pValues);
        CheckError();
    }
    
    void GLSLUniform::Set3iv(const GLint *pValues) const
    {
        // TODO: Should be tested
        glUniform3iv(GetLocation(), GetSize(), pValues);
        CheckError();
    }
    
    void GLSLUniform::Set4iv(const GLint *pValues) const
    {
        // TODO: Should be tested
        glUniform4iv(GetLocation(), GetSize(), pValues);
        CheckError();
    }
    
    void GLSLUniform::SetMatrix2f(const GLSLMatrix2 &rMatrix) const
    {
        // TODO: Should be tested
        glUniformMatrix2fv(GetLocation(), GetSize(), GLSL_FALSE, rMatrix.Pointer());
        CheckError();
    }
    
    void GLSLUniform::SetMatrix3f(const GLSLMatrix3 &rMatrix) const
    {
        // TODO: Should be tested
        glUniformMatrix3fv(GetLocation(), GetSize(), GLSL_FALSE, rMatrix.Pointer());
        CheckError();
    }
    
    void GLSLUniform::SetMatrix4f(const GLSLMatrix4 &rMatrix) const
    {
        // TODO: Should be tested
        glUniformMatrix4fv(GetLocation(), GetSize(), GLSL_FALSE, rMatrix.Pointer());
        CheckError();
    }
    
    void GLSLUniform::SetMatrix2fv(const GLSLMatrix2 *pMatrix) const
    {
        // TODO: Should be tested
        glUniformMatrix2fv(GetLocation(), GetSize(), GLSL_FALSE, (GLfloat *)pMatrix);
        CheckError();
    }
    
    void GLSLUniform::SetMatrix3fv(const GLSLMatrix3 *pMatrix) const
    {
        // TODO: Should be tested
        glUniformMatrix3fv(GetLocation(), GetSize(), GLSL_FALSE, (GLfloat *)pMatrix);
        CheckError();
    }
    
    void GLSLUniform::SetMatrix4fv(const GLSLMatrix4 *pMatrix) const
    {
        // TODO: Should be tested
        glUniformMatrix4fv(GetLocation(), GetSize(), GLSL_FALSE, (GLfloat *)pMatrix);
        CheckError();
    }
    
    GLfloat GLSLUniform::Get1f() const
    {
        // TODO: Should be tested
        GLfloat *pValue = NULL;
        GetValue(pValue);
        
        GLfloat value = *pValue;
        return value;
    }
    
    void GLSLUniform::Get2f(GLfloat *pValue0, GLfloat *pValue1) const
    {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        GetValue(pValues);
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
    }
    
    void GLSLUniform::Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const
    {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        GetValue(pValues);
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
    }
    
    void GLSLUniform::Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const
    {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        GetValue(pValues);
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
        *pValue3 = pValues[3];
    }
    
    GLint GLSLUniform::Get1i() const
    {
        // TODO: Should be tested
        GLint *pValue = NULL;
        GetValue(pValue);
        
        GLint value = *pValue;
        return value;
    }
    
    void GLSLUniform::Get2i(GLint *pValue0, GLint *pValue1) const
    {
        // TODO: Should be tested
        GLint *pValues = NULL;
        GetValue(pValues);
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
    }
    
    void GLSLUniform::Get3i(GLint *pValue0, GLint *pValue1, GLint *pValue2) const
    {
        // TODO: Should be tested
        GLint *pValues = NULL;
        GetValue(pValues);
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
    }
    
    void GLSLUniform::Get4i(GLint *pValue0, GLint *pValue1, GLint *pValue2, GLint *pValue3) const
    {
        // TODO: Should be tested
        GLint *pValues = NULL;
        GetValue(pValues);
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
        *pValue3 = pValues[3];
    }
    
    void GLSLUniform::Get1fv(GLfloat *pValue) const
    {
        // TODO: Should be tested
        GetValue(pValue);
    }
    
    void GLSLUniform::Get2fv(GLfloat *pValues) const
    {
        // TODO: Should be tested
        GetValue(pValues);
    }
    
    void GLSLUniform::Get3fv(GLfloat *pValues) const
    {
        // TODO: Should be tested
        GetValue(pValues);
    }
    
    void GLSLUniform::Get4fv(GLfloat *pValues) const
    {
        // TODO: Should be tested
        GetValue(pValues);
    }
    
    void GLSLUniform::Get1iv(GLint *pValue) const
    {
        // TODO: Should be tested
        GetValue(pValue);
    }
    
    void GLSLUniform::Get2iv(GLint *pValues) const
    {
        // TODO: Should be tested
        GetValue(pValues);
    }
    
    void GLSLUniform::Get3iv(GLint *pValues) const
    {
        // TODO: Should be tested
        GetValue(pValues);
    }
    
    void GLSLUniform::Get4iv(GLint *pValues) const
    {
        // TODO: Should be tested
        GetValue(pValues);
    }
    
    GLSLMatrix2 GLSLUniform::GetMatrix2f() const
    {
        // TODO: Should be tested
        GLSLMatrix2 matrix;
        GetValue((GLfloat *)matrix.Pointer());
        return matrix;
    }
    
    GLSLMatrix3 GLSLUniform::GetMatrix3f() const
    {
        // TODO: Should be tested
        GLSLMatrix3 matrix;
        GetValue((GLfloat *)matrix.Pointer());
        return matrix;
    }
    
    GLSLMatrix4 GLSLUniform::GetMatrix4f() const
    {
        // TODO: Should be tested
        GLSLMatrix4 matrix;
        GetValue((GLfloat *)matrix.Pointer());
        return matrix;
    }
    
    void GLSLUniform::GetMatrix2fv(GLSLMatrix2 *pMatrix) const
    {
        // TODO: Should be tested
        GetValue((GLfloat *)pMatrix);
    }
    
    void GLSLUniform::GetMatrix3fv(GLSLMatrix3 *pMatrix) const
    {
        // TODO: Should be tested
        GetValue((GLfloat *)pMatrix);
    }
    
    void GLSLUniform::GetMatrix4fv(GLSLMatrix4 *pMatrix) const
    {
        // TODO: Should be tested
        GetValue((GLfloat *)pMatrix);
    }
    
#pragma mark - Private Methods
    
    void GLSLUniform::GetValue(GLfloat *pValue) const
    {
        GLuint programHandle = GetProgram()->GetProgramHandle();
        glGetUniformfv(programHandle, GetLocation(), pValue);
        CheckError();
    }
    
    void GLSLUniform::GetValue(GLint *pValue) const
    {
        GLuint programHandle = GetProgram()->GetProgramHandle();
        glGetUniformiv(programHandle, GetLocation(), pValue);
        CheckError();
    }
}