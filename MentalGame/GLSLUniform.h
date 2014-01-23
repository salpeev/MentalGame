//
//  GLSLUniform.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLShaderValue.h"



namespace Renderer
{
    class GLSLUniform: public GLSLShaderValue
    {
    public:
        GLSLUniform(GLSLProgram *pProgram, GLchar *name, GLenum type, GLint size, GLint location);
        
        void Set1f(GLfloat value) const;
        void Set2f(GLfloat value0, GLfloat value1) const;
        void Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const;
        void Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const;
        void Set1i(GLint value) const;
        void Set2i(GLint value0, GLint value1) const;
        void Set3i(GLint value0, GLint value1, GLint value2) const;
        void Set4i(GLint value0, GLint value1, GLint value2, GLint value3) const;
        void Set1fv(const GLfloat *pValue) const;
        void Set2fv(const GLfloat *pValues) const;
        void Set3fv(const GLfloat *pValues) const;
        void Set4fv(const GLfloat *pValues) const;
        void Set1iv(const GLint *pValue) const;
        void Set2iv(const GLint *pValues) const;
        void Set3iv(const GLint *pValues) const;
        void Set4iv(const GLint *pValues) const;
        void SetMatrix2f(const GLSLMatrix2 &rMatrix) const;
        void SetMatrix3f(const GLSLMatrix3 &rMatrix) const;
        void SetMatrix4f(const GLSLMatrix4 &rMatrix) const;
        void SetMatrix2fv(const GLSLMatrix2 *pMatrix) const;
        void SetMatrix3fv(const GLSLMatrix3 *pMatrix) const;
        void SetMatrix4fv(const GLSLMatrix4 *pMatrix) const;
        
        GLfloat Get1f() const;
        void Get2f(GLfloat *pValue0, GLfloat *pValue1) const;
        void Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const;
        void Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const;
        GLint Get1i() const;
        void Get2i(GLint *pValue0, GLint *pValue1) const;
        void Get3i(GLint *pValue0, GLint *pValue1, GLint *pValue2) const;
        void Get4i(GLint *pValue0, GLint *pValue1, GLint *pValue2, GLint *pValue3) const;
        void Get1fv(GLfloat *pValue) const;
        void Get2fv(GLfloat *pValues) const;
        void Get3fv(GLfloat *pValues) const;
        void Get4fv(GLfloat *pValues) const;
        void Get1iv(GLint *pValue) const;
        void Get2iv(GLint *pValues) const;
        void Get3iv(GLint *pValues) const;
        void Get4iv(GLint *pValues) const;
        GLSLMatrix2 GetMatrix2f() const;
        GLSLMatrix3 GetMatrix3f() const;
        GLSLMatrix4 GetMatrix4f() const;
        void GetMatrix2fv(GLSLMatrix2 *pMatrix) const;
        void GetMatrix3fv(GLSLMatrix3 *pMatrix) const;
        void GetMatrix4fv(GLSLMatrix4 *pMatrix) const;
        
    private:
        void GetValue(GLfloat *pValue) const;
        void GetValue(GLint *pValue) const;
    };
}
