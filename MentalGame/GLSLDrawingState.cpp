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
#include "GLLogger.h"
#include <stdlib.h>



namespace GLRenderer
{
    
#pragma mark - GLSLDrawingState
    
    GLSLDrawingState::GLSLDrawingState(GLSLDrawingStateDelegate *pDelegate): m_delegate(pDelegate), m_startDrawIndex(0), m_drawElementsCount(0), m_renderMode(GLSL_RENDER_MODE_LINES)
    {
        
    }
    
    GLSLDrawingState::~GLSLDrawingState()
    {
        
    }
    
#pragma mark Public Methods
    
    GLSLDrawingStateDelegate * GLSLDrawingState::GetDelegate() const
    {
        return m_delegate;
    }
    
    void GLSLDrawingState::SetRenderMode(GLSL_RENDER_MODE renderMode)
    {
        m_renderMode = renderMode;
    }
    
    GLSL_RENDER_MODE GLSLDrawingState::GetRenderMode() const
    {
        return m_renderMode;
    }
    
    void GLSLDrawingState::SetStartDrawIndex(GLint startDrawIndex)
    {
        if (startDrawIndex < GetElementsCount())
        {
            m_startDrawIndex = startDrawIndex;
            
            int lastDrawIndex = startDrawIndex + GetDrawElementsCount() - 1;
            if (lastDrawIndex >= GetElementsCount())
            {
                Log("WARNING: Last draw index exeeds available bounds. Truncated drawing elements count");
                int drawElementsCount = GetElementsCount() - startDrawIndex;
                SetDrawElementsCount(drawElementsCount);
            }
        }
        else
        {
            Log("ERROR: Wrong start draw index");
            m_startDrawIndex = 0;
            SetDrawElementsCount(0);
        }
    }
    
    GLint GLSLDrawingState::GetStartDrawIndex() const
    {
        return m_startDrawIndex;
    }
    
    void GLSLDrawingState::SetDrawElementsCount(GLsizei drawElementsCount)
    {
        GLint lastDrawIndex = GetStartDrawIndex() + drawElementsCount - 1;
        if (lastDrawIndex < GetElementsCount())
        {
            m_drawElementsCount = drawElementsCount;
        }
        else
        {
            Log("WARNING: Last draw index exeeds available bounds. Truncated drawing elements count");
            m_drawElementsCount = GetElementsCount() - GetStartDrawIndex();
        }
    }
    
    GLsizei GLSLDrawingState::GetDrawElementsCount() const
    {
        return m_drawElementsCount;
    }
    
    void GLSLDrawingState::ResetStartDrawIndex()
    {
        SetStartDrawIndex(0);
    }
    
    void GLSLDrawingState::ResetDrawCount()
    {
        GLsizei drawCount = GetElementsCount() - GetStartDrawIndex();
        SetDrawElementsCount(drawCount);
    }
    
    void GLSLDrawingState::ResetStartDrawIndexAndDrawElementsCount()
    {
        ResetStartDrawIndex();
        ResetDrawCount();
    }
    
    
    
#pragma mark - GLSLDrawingVertexBufferIndexBufferState
    
    GLSLVertexBufferIndexBufferState::GLSLVertexBufferIndexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer), m_indexBuffer(pIndexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferIndexBufferState::GetElementsCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferIndexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
        
        GetDelegate()->PerformAttributesInitialization();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesState
    
    GLSLVertexBufferShortIndicesState::GLSLVertexBufferShortIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexBufferShortIndicesState::~GLSLVertexBufferShortIndicesState()
    {
        delete m_indices;
    }
    
    GLsizei GLSLVertexBufferShortIndicesState::GetElementsCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferShortIndicesState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->PerformAttributesInitialization();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesState
    
    GLSLVertexBufferByteIndicesState::GLSLVertexBufferByteIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexBufferByteIndicesState::~GLSLVertexBufferByteIndicesState()
    {
        delete m_indices;
    }
    
    GLsizei GLSLVertexBufferByteIndicesState::GetElementsCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferByteIndicesState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->PerformAttributesInitialization();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferState
    
    GLSLVertexBufferState::GLSLVertexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_vertexBuffer(pVertexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferState::GetElementsCount() const
    {
        return m_vertexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        
        GetDelegate()->PerformAttributesInitialization();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferState
    
    GLSLVertexArrayIndexBufferState::GLSLVertexArrayIndexBufferState(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate), m_indexBuffer(pIndexBuffer)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayIndexBufferState::~GLSLVertexArrayIndexBufferState()
    {
        delete m_vertexArray;
    }
    
    GLsizei GLSLVertexArrayIndexBufferState::GetElementsCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayIndexBufferState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
        
        GetDelegate()->PerformAttributesInitialization(m_vertexArray->GetData());
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesState
    
    GLSLVertexArrayShortIndicesState::GLSLVertexArrayShortIndicesState(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayShortIndicesState::~GLSLVertexArrayShortIndicesState()
    {
        delete m_vertexArray;
        delete m_indices;
    }
    
    GLsizei GLSLVertexArrayShortIndicesState::GetElementsCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayShortIndicesState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->PerformAttributesInitialization(m_vertexArray->GetData());
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesState
    
    GLSLVertexArrayByteIndicesState::GLSLVertexArrayByteIndicesState(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayByteIndicesState::~GLSLVertexArrayByteIndicesState()
    {
        delete m_vertexArray;
        delete m_indices;
    }
    
    GLsizei GLSLVertexArrayByteIndicesState::GetElementsCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayByteIndicesState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->PerformAttributesInitialization(m_vertexArray->GetData());
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
#pragma mark - GLSLVertexArrayState
    
    GLSLVertexArrayState::GLSLVertexArrayState(GLSLVertexArray &rVertexArray, GLSLDrawingStateDelegate *pDelegate): GLSLDrawingState(pDelegate)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayState::~GLSLVertexArrayState()
    {
        delete m_vertexArray;
    }
    
    GLsizei GLSLVertexArrayState::GetElementsCount() const
    {
        return m_vertexArray->GetVerticesCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        
        GetDelegate()->PerformAttributesInitialization(m_vertexArray->GetData());
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
#pragma mark - GLSLRawVertexDataArraysIndexBufferState
    
#pragma mark - GLSLRawVertexDataArraysRawShortIndicesState
    
#pragma mark - GLSLRawVertexDataArraysRawByteIndicesState
    
#pragma mark - GLSLRawVertexDataArraysState
    
}