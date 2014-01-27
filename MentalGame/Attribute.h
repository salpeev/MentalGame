//
//  Attribute.h
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "ShaderValue.h"
#include "GLConstants.h"

using namespace std;



namespace Renderer {
    
    class Attribute: public ShaderValue {
    public:
        Attribute(Program *pProgram, GLchar *name, GLenum type, GLint size, GLint location);
        
        // TODO: Test for GL_MAX_VERTEX_ATTRIBS
        
        void SetBufferPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, GLsizei offset) const;
        void SetDataPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, const GLvoid *pData) const;
        
        void Set1f(GLfloat value) const;
        void Set2f(GLfloat value0, GLfloat value1) const;
        void Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const;
        void Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const;
        void Set1fv(const GLfloat *pValue) const;
        void Set2fv(const GLfloat *pValues) const;
        void Set3fv(const GLfloat *pValues) const;
        void Set4fv(const GLfloat *pValues) const;
        
        GLfloat Get1f() const;
        void Get2f(GLfloat *pValue0, GLfloat *pValue1) const;
        void Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const;
        void Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const;
        void Get1fv(GLfloat *pValue) const;
        void Get2fv(GLfloat *pValues) const;
        void Get3fv(GLfloat *pValues) const;
        void Get4fv(GLfloat *pValues) const;
        
    private:
        void EnableArray() const;
        void DisableArray() const;
        bool IsArrayEnabled() const;
    };
}
