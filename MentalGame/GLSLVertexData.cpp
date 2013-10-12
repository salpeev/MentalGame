//
//  GLSLVertexData.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertexData.h"



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
        
        return &m_data[0];
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
    
    
    
    void GLSLVertexData1C::AddVertex(GLSLVertex *pVertex) const
    {
        GLColor color = ((GLSLVertex1C *)pVertex)->GetColor();
        AddValue(color.r);
        AddValue(color.g);
        AddValue(color.b);
        AddValue(color.a);
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
}