//
//  GLSLVertexData.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 04.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertexArray.h"
#include <stdlib.h>
#include <string>



namespace GLRenderer
{
    GLSLVertexArray::GLSLVertexArray(GLvoid *pData, GLsizei vertexSize, GLuint verticesCount): m_vertexSize(vertexSize), m_verticesCount(verticesCount)
    {
        m_dataSize = vertexSize * verticesCount;
        
        m_data = malloc(m_dataSize);
        memcpy(m_data, pData, m_dataSize);
    }
    
    GLSLVertexArray::GLSLVertexArray(const GLSLVertexArray &rVertexArray)
    {
        m_dataSize = rVertexArray.m_dataSize;
        m_vertexSize = rVertexArray.m_vertexSize;
        m_verticesCount = rVertexArray.m_verticesCount;
        
        m_data = malloc(m_dataSize);
        memcpy(m_data, rVertexArray.GetData(), m_dataSize);
    }
    
    GLSLVertexArray::~GLSLVertexArray()
    {
        free(m_data);
    }
    
    GLvoid * GLSLVertexArray::GetData() const
    {
        return m_data;
    }
    
    GLsizei GLSLVertexArray::GetDataSize() const
    {
        return m_dataSize;
    }
    
    GLsizei GLSLVertexArray::GetVertexSize() const
    {
        return m_vertexSize;
    }
    
    GLuint GLSLVertexArray::GetVerticesCount() const
    {
        return m_verticesCount;
    }
}
