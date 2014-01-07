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
    
    GLSLDrawingState::GLSLDrawingState(): m_startDrawIndex(0), m_drawElementsCount(0), m_renderMode(GLSL_RENDER_MODE_LINES)
    {
        
    }
    
    GLSLDrawingState::~GLSLDrawingState()
    {
        
    }
    
#pragma mark Public Methods
    
    void GLSLDrawingState::SetProgramInitializer(GLSLProgramInitializer *pProgramInitializer)
    {
        m_programInitializer = pProgramInitializer;
    }
    
    GLSLProgramInitializer * GLSLDrawingState::GetProgramInitializer() const
    {
        return m_programInitializer;
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
        if (startDrawIndex < GetVerticesCount())
        {
            m_startDrawIndex = startDrawIndex;
            
            int lastDrawIndex = startDrawIndex + GetDrawElementsCount() - 1;
            if (lastDrawIndex >= GetVerticesCount())
            {
                Log("WARNING: Last draw index exeeds available bounds. Truncated drawing elements count");
                int drawElementsCount = GetVerticesCount() - startDrawIndex;
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
        if (lastDrawIndex < GetVerticesCount())
        {
            m_drawElementsCount = drawElementsCount;
        }
        else
        {
            Log("WARNING: Last draw index exeeds available bounds. Truncated drawing elements count");
            m_drawElementsCount = GetVerticesCount() - GetStartDrawIndex();
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
        GLsizei drawCount = GetVerticesCount() - GetStartDrawIndex();
        SetDrawElementsCount(drawCount);
    }
    
    void GLSLDrawingState::ResetStartDrawIndexAndDrawElementsCount()
    {
        ResetStartDrawIndex();
        ResetDrawCount();
    }
    
    
    
#pragma mark - GLSLDrawingVertexBufferIndexBufferState
    
    GLSLVertexBufferIndexBufferState::GLSLVertexBufferIndexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer): m_vertexBuffer(pVertexBuffer), m_indexBuffer(pIndexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferIndexBufferState::GetVerticesCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferIndexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
        
        GetProgramInitializer()->InitializeAttributesWithCurrentBuffer();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesState
    
    GLSLVertexBufferShortIndicesState::GLSLVertexBufferShortIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices): m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexBufferShortIndicesState::~GLSLVertexBufferShortIndicesState()
    {
        delete m_indices;
    }
    
    GLsizei GLSLVertexBufferShortIndicesState::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferShortIndicesState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributesWithCurrentBuffer();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesState
    
    GLSLVertexBufferByteIndicesState::GLSLVertexBufferByteIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices): m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexBufferByteIndicesState::~GLSLVertexBufferByteIndicesState()
    {
        delete m_indices;
    }
    
    GLsizei GLSLVertexBufferByteIndicesState::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferByteIndicesState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributesWithCurrentBuffer();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferState
    
    GLSLVertexBufferState::GLSLVertexBufferState(GLSLVertexBuffer *pVertexBuffer): m_vertexBuffer(pVertexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferState::GetVerticesCount() const
    {
        return m_vertexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferState::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        
        GetProgramInitializer()->InitializeAttributesWithCurrentBuffer();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferState
    
    GLSLVertexArrayIndexBufferState::GLSLVertexArrayIndexBufferState(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer): m_indexBuffer(pIndexBuffer)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayIndexBufferState::~GLSLVertexArrayIndexBufferState()
    {
        delete m_vertexArray;
    }
    
    GLsizei GLSLVertexArrayIndexBufferState::GetVerticesCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayIndexBufferState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
        
        GetProgramInitializer()->InitializeAttributesWithVertexArray(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesState
    
    GLSLVertexArrayShortIndicesState::GLSLVertexArrayShortIndicesState(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices)
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
    
    GLsizei GLSLVertexArrayShortIndicesState::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayShortIndicesState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributesWithVertexArray(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesState
    
    GLSLVertexArrayByteIndicesState::GLSLVertexArrayByteIndicesState(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices)
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
    
    GLsizei GLSLVertexArrayByteIndicesState::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayByteIndicesState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributesWithVertexArray(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
#pragma mark - GLSLVertexArrayState
    
    GLSLVertexArrayState::GLSLVertexArrayState(GLSLVertexArray &rVertexArray)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayState::~GLSLVertexArrayState()
    {
        delete m_vertexArray;
    }
    
    GLsizei GLSLVertexArrayState::GetVerticesCount() const
    {
        return m_vertexArray->GetVerticesCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayState::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributesWithVertexArray(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
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