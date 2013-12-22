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
#include "GLLogger.h"
#include <stdlib.h>




namespace GLRenderer
{
    GLSLDrawingState::GLSLDrawingState(GLSLDrawingStateDelegate *pDelegate): m_delegate(pDelegate)
    {
        
    }
    
    GLSLDrawingState::~GLSLDrawingState()
    {
        
    }
    
    GLSLDrawingStateDelegate * GLSLDrawingState::GetDelegate() const
    {
        return m_delegate;
    }
    
    
    
    GLSLVertexBufferIndexBufferState::GLSLVertexBufferIndexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer), m_indexBuffer(pIndexBuffer)
    {
        
    }
    
    void GLSLVertexBufferIndexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
        
        GetDelegate()->InitializeAttributes();
        
        GLuint elementsCount = m_indexBuffer->GetElementsCount();
        GLenum type = GLDataConverter::OpenGLESDataTypeFromDataType(m_indexBuffer->GetDataType());
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, elementsCount, type, NULL);
        CheckError();
    }
    
    
    
    GLSLVertexBufferShortIndicesState::GLSLVertexBufferShortIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer)
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
        
        GetDelegate()->InitializeAttributes();
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_SHORT, (GLvoid *)(&m_indices[0]));
        CheckError();
    }
    
    
    
    GLSLVertexBufferByteIndicesState::GLSLVertexBufferByteIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer)
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
        
        GetDelegate()->InitializeAttributes();
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_BYTE, (GLvoid *)(&m_indices[0]));
        CheckError();
    }
    
    
    
    GLSLVertexBufferState::GLSLVertexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer)
    {
        
    }
    
    void GLSLVertexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        // TODO: Should be disabled or not for improving performance?
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->InitializeAttributes();
        
        // TODO: Implement partial buffer drawing
        glDrawArrays(GL_LINES, 0, m_vertexBuffer->GetElementsCount());
        CheckError();
    }
    
    
    
    GLSLRawVertexDataIndexBufferState::GLSLRawVertexDataIndexBufferState(GLvoid *pData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_indexBuffer(pIndexBuffer)
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
        
        GetDelegate()->InitializeAttributes();
        
        GLuint elementsCount = m_indexBuffer->GetElementsCount();
        GLenum type = GLDataConverter::OpenGLESDataTypeFromDataType(m_indexBuffer->GetDataType());
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, elementsCount, type, NULL);
        CheckError();
    }
    
    
    
    GLSLRawVertexDataRawShortIndicesState::GLSLRawVertexDataRawShortIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate)
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
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->InitializeAttributes(m_data);
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_SHORT, (GLvoid *)(&m_indices->at(0)));
        CheckError();
    }
    
    
    
    GLSLRawVertexDataRawByteIndicesState::GLSLRawVertexDataRawByteIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate)
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
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->InitializeAttributes(m_data);
        
        // TODO: Implement partial buffer drawing
        glDrawElements(GL_LINES, m_indices->size(), GL_UNSIGNED_BYTE, (GLvoid *)(&m_indices->at(0)));
        CheckError();
    }
    
    
    
    GLSLRawVertexDataState::GLSLRawVertexDataState(GLvoid *pData, GLsizei elementSize, GLuint elementsCount, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_elementsCount(elementsCount)
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
//        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->InitializeAttributes(m_data);
        
        // TODO: Implement partial buffer drawing
        glDrawArrays(GL_LINES, 0, m_elementsCount);
        CheckError();
    }
}