//
//  GLSLDrawingState.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawingState.h"
#include <stdlib.h>




namespace GLRenderer
{
    GLSLDrawingState::GLSLDrawingState()
    {
        
    }
    
    GLSLDrawingState::~GLSLDrawingState()
    {
        
    }
    
    
    
    GLSLVertexBufferIndexBufferState::GLSLVertexBufferIndexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer): GLSLDrawingState(), m_vertexBuffer(pVertexBuffer), m_indexBuffer(pIndexBuffer)
    {
        
    }
    
    void GLSLVertexBufferIndexBufferState::Activate() const
    {
        
    }
    
    
    
    GLSLVertexBufferShortIndicesState::GLSLVertexBufferShortIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices): GLSLDrawingState(), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLushort>(rIndices);
    }
    
    GLSLVertexBufferShortIndicesState::~GLSLVertexBufferShortIndicesState()
    {
        delete m_indices;
    }
    
    void GLSLVertexBufferShortIndicesState::Activate() const
    {
        
    }
    
    
    
    GLSLVertexBufferByteIndicesState::GLSLVertexBufferByteIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices): GLSLDrawingState(), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLubyte>(rIndices);
    }
    
    GLSLVertexBufferByteIndicesState::~GLSLVertexBufferByteIndicesState()
    {
        delete m_indices;
    }
    
    void GLSLVertexBufferByteIndicesState::Activate() const
    {
        
    }
    
    
    
    GLSLVertexBufferState::GLSLVertexBufferState(GLSLVertexBuffer *pVertexBuffer): GLSLDrawingState(), m_vertexBuffer(pVertexBuffer)
    {
        
    }
    
    void GLSLVertexBufferState::Activate() const
    {
        
    }
    
    
    
    GLSLRawVertexDataIndexBufferState::GLSLRawVertexDataIndexBufferState(GLvoid *pData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer): GLSLDrawingState(), m_indexBuffer(pIndexBuffer)
    {
        m_data = malloc(dataSize);
        memcpy(m_data, pData, dataSize);
    }
    
    GLSLRawVertexDataIndexBufferState::~GLSLRawVertexDataIndexBufferState()
    {
        free(m_data);
    }
    
    void GLSLRawVertexDataIndexBufferState::Activate() const
    {
        
    }
    
    
    
    GLSLRawVertexDataRawShortIndicesState::GLSLRawVertexDataRawShortIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLushort> &rIndices)
    {
        m_data = malloc(dataSize);
        memcpy(m_data, pData, dataSize);
        
        m_indices = new vector<GLushort>(rIndices);
    }
    
    GLSLRawVertexDataRawShortIndicesState::~GLSLRawVertexDataRawShortIndicesState()
    {
        free(m_data);
        delete m_indices;
    }
    
    void GLSLRawVertexDataRawShortIndicesState::Activate() const
    {
        
    }
    
    
    
    GLSLRawVertexDataRawByteIndicesState::GLSLRawVertexDataRawByteIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLubyte> &rIndices)
    {
        m_data = malloc(dataSize);
        memcpy(m_data, pData, dataSize);
        
        m_indices = new vector<GLubyte>(rIndices);
    }
    
    GLSLRawVertexDataRawByteIndicesState::~GLSLRawVertexDataRawByteIndicesState()
    {
        free(m_data);
        delete m_indices;
    }
    
    void GLSLRawVertexDataRawByteIndicesState::Activate() const
    {
        
    }
    
    
    GLSLRawVertexDataState::GLSLRawVertexDataState(GLvoid *pData, GLsizei dataSize): GLSLDrawingState()
    {
        m_data = malloc(dataSize);
        memcpy(m_data, pData, dataSize);
    }
    
    GLSLRawVertexDataState::~GLSLRawVertexDataState()
    {
        free(m_data);
    }
    
    void GLSLRawVertexDataState::Activate() const
    {
        
    }
}