//
//  Attribute.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Attribute.h"
#include "Constants.h"
#include "Logger.h"



namespace Renderer {
    
    Attribute::Attribute(Program *pProgram, GLchar *name, GLenum type, GLint size, GLint location): ShaderValue(pProgram, name, type, size, location) {
        
    }
    
#pragma mark - Public Methods
    
    void Attribute::SetBufferPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, GLsizei offset) const {
        EnableArray();
        
        glVertexAttribPointer(GetLocation(), size, type, normalized, stride, (GLvoid *)offset);
        CheckError();
    }
    
    void Attribute::SetDataPointer(GLsizei size, GLSL_DATA_TYPE type, bool normalized, GLsizei stride, const GLvoid *pData) const {
        EnableArray();
        
        glVertexAttribPointer(GetLocation(), size, type, normalized, stride, pData);
        CheckError();
    }
    
    void Attribute::Set1f(GLfloat value) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib1f(GetLocation(), value);
        CheckError();
    }
    
    void Attribute::Set2f(GLfloat value0, GLfloat value1) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib2f(GetLocation(), value0, value1);
        CheckError();
    }
    
    void Attribute::Set3f(GLfloat value0, GLfloat value1, GLfloat value2) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib3f(GetLocation(), value0, value1, value2);
        CheckError();
    }
    
    void Attribute::Set4f(GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib4f(GetLocation(), value0, value1, value2, value3);
        CheckError();
    }
    
    void Attribute::Set1fv(const GLfloat *pValue) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib1fv(GetLocation(), pValue);
        CheckError();
    }
    
    void Attribute::Set2fv(const GLfloat *pValues) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib2fv(GetLocation(), pValues);
        CheckError();
    }
    
    void Attribute::Set3fv(const GLfloat *pValues) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib3fv(GetLocation(), pValues);
        CheckError();
    }
    
    void Attribute::Set4fv(const GLfloat *pValues) const {
        // TODO: Should be tested
        DisableArray();
        
        glVertexAttrib4fv(GetLocation(), pValues);
        CheckError();
    }
    
    GLfloat Attribute::Get1f() const {
        // TODO: Should be tested
        GLfloat *pValue = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValue);
        CheckError();
        
        GLfloat value = *pValue;
        return value;
    }
    
    void Attribute::Get2f(GLfloat *pValue0, GLfloat *pValue1) const {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
    }
    
    void Attribute::Get3f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2) const {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
    }
    
    void Attribute::Get4f(GLfloat *pValue0, GLfloat *pValue1, GLfloat *pValue2, GLfloat *pValue3) const {
        // TODO: Should be tested
        GLfloat *pValues = NULL;
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
        
        *pValue0 = pValues[0];
        *pValue1 = pValues[1];
        *pValue2 = pValues[2];
        *pValue3 = pValues[3];
    }
    
    void Attribute::Get1fv(GLfloat *pValue) const {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValue);
        CheckError();
    }
    
    void Attribute::Get2fv(GLfloat *pValues) const {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
    }
    
    void Attribute::Get3fv(GLfloat *pValues) const {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
    }
    
    void Attribute::Get4fv(GLfloat *pValues) const {
        // TODO: Should be tested
        glGetVertexAttribfv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB, pValues);
        CheckError();
    }
    
#pragma mark - Private Methods
    
    void Attribute::EnableArray() const {
        if (!IsArrayEnabled()) {
            glEnableVertexAttribArray(GetLocation());
            CheckError();
        }
    }
    
    void Attribute::DisableArray() const {
        if (IsArrayEnabled()) {
            glDisableVertexAttribArray(GetLocation());
            CheckError();
        }
    }
    
    bool Attribute::IsArrayEnabled() const {
        GLint arrayEnabled;
        glGetVertexAttribiv(GetLocation(), GLSL_GET_VERTEX_ATTRIB_ARRAY_ENABLED, &arrayEnabled);
        CheckError();
        
        bool enabled = (arrayEnabled == GLSL_TRUE);
        return enabled;
    }
}