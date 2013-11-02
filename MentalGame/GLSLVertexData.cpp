//
//  GLSLVertexData.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertexData.h"
#include "GLConstants.h"



namespace GLRenderer
{
    GLSLVertexData::GLSLVertexData()
    {
        m_data = new vector<GLfloat>;
    }
    
    GLSLVertexData::~GLSLVertexData()
    {
        delete m_data;
    }
    
    GLvoid * GLSLVertexData::GetDataPointer() const
    {
        if (m_data->size() == 0)
        {
            return NULL;
        }
        
        return &m_data->at(0);
    }
    
    GLsizeiptr GLSLVertexData::GetDataCount() const
    {
        return m_data->size();
    }
    
    void GLSLVertexData::AddValue(GLfloat value) const
    {
        m_data->push_back(value);
    }
    
    
    
    void GLSLVertexData1P::AddVertex(GLSLVertex *pVertex) const
    {
        GLPoint point = ((GLSLVertex1P *)pVertex)->GetPosition();
        AddValue(point.x);
        AddValue(point.y);
        AddValue(point.z);
    }
    
    GLint GLSLVertexData1P::GetSizeAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return GLSL_FLOATS_3;
            default: return GLSL_FLOATS_0;
        }
    }
    
    GLint GLSLVertexData1P::GetMembersCount() const
    {
        return GLSL_MEMBERS_COUNT_1;
    }
    
    GLuint GLSLVertexData1P::GetElementByteSize() const
    {
        return sizeof(GLSLVertex1P);
    }
    
    GLvoid *GLSLVertexData1P::GetOffetAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return NULL;
            default: return NULL;
        }
    }
    
    
    
    void GLSLVertexData1C::AddVertex(GLSLVertex *pVertex) const
    {
        GLColor color = ((GLSLVertex1C *)pVertex)->GetColor();
        AddValue(color.r);
        AddValue(color.g);
        AddValue(color.b);
        AddValue(color.a);
    }
    
    GLint GLSLVertexData1C::GetSizeAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return GLSL_FLOATS_4;
            default: return GLSL_FLOATS_0;
        }
    }
    
    GLint GLSLVertexData1C::GetMembersCount() const
    {
        return GLSL_MEMBERS_COUNT_1;
    }
    
    GLuint GLSLVertexData1C::GetElementByteSize() const
    {
        return sizeof(GLSLVertex1C);
    }
    
    GLvoid *GLSLVertexData1C::GetOffetAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return NULL;
            default: return NULL;
        }
    }
    
    
    
    void GLSLVertexData1P1C::AddVertex(GLSLVertex *pVertex) const
    {
        GLPoint point = ((GLSLVertex1P1C *)pVertex)->GetPosition();
        AddValue(point.x);
        AddValue(point.y);
        AddValue(point.z);
        
        GLColor color = ((GLSLVertex1P1C *)pVertex)->GetColor();
        AddValue(color.r);
        AddValue(color.g);
        AddValue(color.b);
        AddValue(color.a);
    }
    
    GLint GLSLVertexData1P1C::GetSizeAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return GLSL_FLOATS_3;
            case 1: return GLSL_FLOATS_4;
            default: return GLSL_FLOATS_0;
        }
    }
    
    GLint GLSLVertexData1P1C::GetMembersCount() const
    {
        return GLSL_MEMBERS_COUNT_2;
    }
    
    GLuint GLSLVertexData1P1C::GetElementByteSize() const
    {
        return sizeof(GLSLVertex1P1C);
    }
    
    GLvoid *GLSLVertexData1P1C::GetOffetAtIndex(GLint index) const
    {
        switch (index) {
            case 0: return NULL;
            case 1: return (GLvoid *)sizeof(GLSLVertex1P);
            default: return NULL;
        }
    }
}