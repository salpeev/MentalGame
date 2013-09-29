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
    
    void GLSLVertexData::AddPoint(GLPoint point) const
    {
        m_data->push_back(point.x);
        m_data->push_back(point.y);
        m_data->push_back(point.z);
    }
    
    void GLSLVertexData::AddColor(GLColor color) const
    {
        m_data->push_back(color.r);
        m_data->push_back(color.g);
        m_data->push_back(color.b);
        m_data->push_back(color.a);
    }
    
    void GLSLVertexData::AddVertex1P1C(GLSLVertex1P1C vertex) const
    {
        AddPoint(vertex.GetPosition());
        AddColor(vertex.GetColor());
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
}