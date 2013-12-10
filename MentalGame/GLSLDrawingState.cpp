//
//  GLSLDrawingState.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawingState.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLDataConverter.h"
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
    
    void GLSLVertexBufferIndexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
        
        GLuint elementsCount = m_indexBuffer->GetElementsCount();
        GLenum type = GLDataConverter::OpenGLESDataTypeFromDataType(m_indexBuffer->GetDataType());
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, elementsCount, type, NULL);
    }
    
    
    
    GLSLVertexBufferShortIndicesState::GLSLVertexBufferShortIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices): GLSLDrawingState(), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLushort>(rIndices);
    }
    
    GLSLVertexBufferShortIndicesState::~GLSLVertexBufferShortIndicesState()
    {
        delete m_indices;
    }
    
    void GLSLVertexBufferShortIndicesState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_SHORT, (GLvoid *)(&m_indices[0]));
    }
    
    
    
    GLSLVertexBufferByteIndicesState::GLSLVertexBufferByteIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices): GLSLDrawingState(), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLubyte>(rIndices);
    }
    
    GLSLVertexBufferByteIndicesState::~GLSLVertexBufferByteIndicesState()
    {
        delete m_indices;
    }
    
    void GLSLVertexBufferByteIndicesState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_BYTE, (GLvoid *)(&m_indices[0]));
    }
    
    
    
    GLSLVertexBufferState::GLSLVertexBufferState(GLSLVertexBuffer *pVertexBuffer): GLSLDrawingState(), m_vertexBuffer(pVertexBuffer)
    {
        
    }
    
    void GLSLVertexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        // TODO: Should be disabled or not for improving performance?
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        // TODO: Implement partial buffer drawing
        glDrawArrays(GL_LINES, 0, m_vertexBuffer->GetElementsCount());
    }
    
    
    
    GLSLRawVertexDataIndexBufferState::GLSLRawVertexDataIndexBufferState(GLvoid *pData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer): GLSLDrawingState(), m_indexBuffer(pIndexBuffer)
    {
        // TODO: Is this data should be copied? Not used in PerformDrawing()
        m_data = malloc(dataSize);
        memcpy(m_data, pData, dataSize);
    }
    
    GLSLRawVertexDataIndexBufferState::~GLSLRawVertexDataIndexBufferState()
    {
        free(m_data);
    }
    
    void GLSLRawVertexDataIndexBufferState::PerformDrawing() const
    {
        // TODO: Should be disabled or not for improving performance?
//        GLSLVertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
        
        GLuint elementsCount = m_indexBuffer->GetElementsCount();
        GLenum type = GLDataConverter::OpenGLESDataTypeFromDataType(m_indexBuffer->GetDataType());
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, elementsCount, type, NULL);
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
    
    void GLSLRawVertexDataRawShortIndicesState::PerformDrawing() const
    {
        // TODO: Should be disabled or not for improving performance?
//        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_SHORT, (GLvoid *)(&m_indices[0]));
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
    
    void GLSLRawVertexDataRawByteIndicesState::PerformDrawing() const
    {
        // TODO: Should be disabled or not for improving performance?
        //        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_BYTE, (GLvoid *)(&m_indices[0]));
    }
    
    
    
    GLSLRawVertexDataState::GLSLRawVertexDataState(GLvoid *pData, GLsizei elementSize, GLuint elementsCount): GLSLDrawingState(), m_elementsCount(elementsCount)
    {
        GLsizei dataSize = elementSize * elementsCount;
        
        m_data = malloc(dataSize);
        memcpy(m_data, pData, dataSize);
    }
    
    GLSLRawVertexDataState::~GLSLRawVertexDataState()
    {
        free(m_data);
    }
    
    void GLSLRawVertexDataState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        // TODO: Should be disabled or not for improving performance?
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        // TODO: Implement partial buffer drawing
        glDrawArrays(GL_LINES, 0, m_elementsCount);
    }
}