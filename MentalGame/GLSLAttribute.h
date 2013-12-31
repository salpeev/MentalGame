//
//  GLSLAttribute.h
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLShaderValue.h"

using namespace std;



namespace GLRenderer
{
    class GLSLAttribute: public GLSLShaderValue
    {
    public:
        GLSLAttribute(GLSLProgram *pProgram, GLchar *name, GLenum type, GLint size, GLint location);
        
        void EnableArray() const;
        void DisableArray() const;
        bool IsArrayEnabled() const;
        
        // TODO: Test for GL_MAX_VERTEX_ATTRIBS
        void Set1f(GLfloat value) const;
        void Set2f(GLfloat value0, GLfloat value1) const;
        void Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const;
        void Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const;
        void Set1fv(const GLfloat *pValue);
        void Set2fv(const GLfloat *pValue);
        void Set3fv(const GLfloat *pValue);
        void Set4fv(const GLfloat *pValue);
        
        GLfloat Get1f() const;
        void Get2f(GLfloat *pValue0, GLfloat *pValue1) const;
        void Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const;
        void Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const;
        void Get1fv(GLfloat *pValue);
        void Get2fv(GLfloat *pValue);
        void Get3fv(GLfloat *pValue);
        void Get4fv(GLfloat *pValue);
        
        // TODO: glVertexAttribPointer should be handled
    };
}
