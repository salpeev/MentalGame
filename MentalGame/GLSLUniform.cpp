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



namespace GLRenderer
{
#pragma mark - Public Methods
    
    GLSLUniform::GLSLUniform(GLSLProgram *pProgram, GLchar *name, GLenum type, GLint size, GLint location): GLSLShaderValue(pProgram, name, type, size, location)
    {
        
    }
    
    void GLSLUniform::Set1f(GLfloat value) const
    {
        
    }
    
    void GLSLUniform::Set2f(GLfloat value0, GLfloat value1) const
    {
        
    }
    
    void GLSLUniform::Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const
    {
        
    }
    
    void GLSLUniform::Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const
    {
        
    }
    
    void GLSLUniform::Set1i(GLint value) const
    {
        
    }
    
    void GLSLUniform::Set2i(GLint value0, GLint value1) const
    {
        
    }
    
    void GLSLUniform::Set3i(GLint value0, GLint value1, GLint value2) const
    {
        
    }
    
    void GLSLUniform::Set4i(GLint value0, GLint value1, GLint value2, GLint value3) const
    {
        
    }
    
    void GLSLUniform::Set1fv(GLsizei count, GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Set2fv(GLsizei count, GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Set3fv(GLsizei count, GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Set4fv(GLsizei count, GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Set1iv(GLsizei count, GLint *pValue) const
    {
        
    }
    
    void GLSLUniform::Set2iv(GLsizei count, GLint *pValue) const
    {
        
    }
    
    void GLSLUniform::Set3iv(GLsizei count, GLint *pValue) const
    {
        
    }
    
    void GLSLUniform::Set4iv(GLsizei count, GLint *pValue) const
    {
        
    }
    
    void GLSLUniform::SetMatrix2f(const GLSLMatrix2 &rMatrix) const
    {
        glUniformMatrix2fv(m_location, m_size, GLSL_FALSE, rMatrix.Pointer());
        CheckError();
    }
    
    void GLSLUniform::SetMatrix3f(const GLSLMatrix3 &rMatrix) const
    {
        glUniformMatrix3fv(m_location, m_size, GLSL_FALSE, rMatrix.Pointer());
        CheckError();
    }
    
    void GLSLUniform::SetMatrix4f(const GLSLMatrix4 &rMatrix) const
    {
        glUniformMatrix4fv(m_location, m_size, GLSL_FALSE, rMatrix.Pointer());
        CheckError();
    }
    
    void GLSLUniform::SetMatrix2fv(const GLSLMatrix2 *pMatrix) const
    {
        
    }
    
    void GLSLUniform::SetMatrix3fv(const GLSLMatrix3 *pMatrix) const
    {
        
    }
    
    void GLSLUniform::SetMatrix4fv(const GLSLMatrix4 *pMatrix) const
    {
        
    }
    
    GLfloat GLSLUniform::Get1f() const
    {
        
    }
    
    void GLSLUniform::Get2f(GLfloat *pValue0, GLfloat *pValue1) const
    {
        
    }
    
    void GLSLUniform::Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const
    {
        
    }
    
    void GLSLUniform::Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const
    {
        
    }
    
    GLfloat GLSLUniform::Get1i() const
    {
        
    }
    
    void GLSLUniform::Get2i(GLint *pValue0, GLint *pValue1) const
    {
        
    }
    
    void GLSLUniform::Get3i(GLint *pValue0, GLint *pValue1, GLint *pValue2) const
    {
        
    }
    
    void GLSLUniform::Get4i(GLint *pValue0, GLint *pValue1, GLint *pValue2, GLint *pValue3) const
    {
        
    }
    
    void GLSLUniform::Get1fv(GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Get2fv(GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Get3fv(GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Get4fv(GLfloat *pValue) const
    {
        
    }
    
    void GLSLUniform::Get1iv(GLint *pValue) const
    {
        
    }
    
    void GLSLUniform::Get2iv(GLint *pValue) const
    {
        
    }
    
    void GLSLUniform::Get3iv(GLint *pValue) const
    {
        
    }
    
    void GLSLUniform::Get4iv(GLint *pValue) const
    {
        
    }
    
    
    GLSLMatrix2 GLSLUniform::GetMatrix2f() const
    {
        GLSLMatrix2 matrix;
        GetValue((GLfloat *)matrix.Pointer());
        return matrix;
    }
    
    GLSLMatrix3 GLSLUniform::GetMatrix3f() const
    {
        GLSLMatrix3 matrix;
        GetValue((GLfloat *)matrix.Pointer());
        return matrix;
    }
    
    GLSLMatrix4 GLSLUniform::GetMatrix4f() const
    {
        GLSLMatrix4 matrix;
        GetValue((GLfloat *)matrix.Pointer());
        return matrix;
    }
    
    void GLSLUniform::GetMatrix2fv(const GLSLMatrix2 *pMatrix) const
    {
        
    }
    
    void GLSLUniform::GetMatrix3fv(const GLSLMatrix3 *pMatrix) const
    {
        
    }
    
    void GLSLUniform::GetMatrix4fv(const GLSLMatrix4 *pMatrix) const
    {
        
    }
    
#pragma mark - Private Methods
    
    void GLSLUniform::GetValue(GLfloat *pValue) const
    {
        GLuint programHandle = GetProgram()->GetProgramHandle();
        glGetUniformfv(programHandle, m_location, pValue);
        CheckError();
    }
    
    void GLSLUniform::GetValue(GLint *pValue) const
    {
        GLuint programHandle = GetProgram()->GetProgramHandle();
        glGetUniformiv(programHandle, m_location, pValue);
        CheckError();
    }
}