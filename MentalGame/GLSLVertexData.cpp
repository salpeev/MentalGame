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
    
    void GLSLVertexData::AddPoint2(GLPoint2 point) const
    {
        m_data->push_back(point.x);
        m_data->push_back(point.y);
    }
    
    void GLSLVertexData::AddPoint3(GLPoint3 point) const
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
    
    GLvoid * GLSLVertexData::DataPointer() const
    {
        if (m_data->size() == 0)
        {
            return NULL;
        }
        
        return &m_data[0];
    }
}