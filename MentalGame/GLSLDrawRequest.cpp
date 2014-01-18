//
//  GLSLDrawRequest.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawRequest.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLLogger.h"
#include <stdlib.h>



namespace GLRenderer
{
    
#pragma mark - GLSLDrawRequest
    
    GLSLDrawRequest::GLSLDrawRequest(GLSLProgramInitializer *pProgramInitializer): m_programInitializer(pProgramInitializer), m_startDrawIndex(0), m_drawElementsCount(0), m_renderMode(GLSL_RENDER_MODE_LINES)
    {
        
    }
    
    GLSLDrawRequest::~GLSLDrawRequest()
    {
        
    }
    
#pragma mark Public Methods
    
    void GLSLDrawRequest::SetRenderMode(GLSL_RENDER_MODE renderMode)
    {
        m_renderMode = renderMode;
    }
    
    void GLSLDrawRequest::SetStartDrawIndex(GLint startDrawIndex)
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
    
    void GLSLDrawRequest::SetDrawElementsCount(GLsizei drawElementsCount)
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
    
    GLSL_RENDER_MODE GLSLDrawRequest::GetRenderMode() const
    {
        return m_renderMode;
    }
    
    GLint GLSLDrawRequest::GetStartDrawIndex() const
    {
        return m_startDrawIndex;
    }
    
    GLsizei GLSLDrawRequest::GetDrawElementsCount() const
    {
        return m_drawElementsCount;
    }
    
    GLSLProgramInitializer * GLSLDrawRequest::GetProgramInitializer() const
    {
        return m_programInitializer;
    }
    
    void GLSLDrawRequest::ResetStartDrawIndex()
    {
        SetStartDrawIndex(0);
    }
    
    void GLSLDrawRequest::ResetDrawCount()
    {
        GLsizei drawCount = GetVerticesCount() - GetStartDrawIndex();
        SetDrawElementsCount(drawCount);
    }
    
    void GLSLDrawRequest::ResetStartDrawIndexAndDrawElementsCount()
    {
        ResetStartDrawIndex();
        ResetDrawCount();
    }
    
    
    
#pragma mark - GLSLDrawingVertexBufferIndexBufferRequest
    
    GLSLVertexBufferIndexBufferRequest::GLSLVertexBufferIndexBufferRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer): GLSLDrawRequest(pProgramInitializer), m_vertexBuffer(pVertexBuffer), m_indexBuffer(pIndexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferIndexBufferRequest::GetVerticesCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferIndexBufferRequest::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
        
        GetProgramInitializer()->InitializeAttributes();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesRequest
    
    GLSLVertexBufferShortIndicesRequest::GLSLVertexBufferShortIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices): GLSLDrawRequest(pProgramInitializer), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexBufferShortIndicesRequest::~GLSLVertexBufferShortIndicesRequest()
    {
        delete m_indices;
    }
    
    GLsizei GLSLVertexBufferShortIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferShortIndicesRequest::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributes();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesRequest
    
    GLSLVertexBufferByteIndicesRequest::GLSLVertexBufferByteIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices): GLSLDrawRequest(pProgramInitializer), m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexBufferByteIndicesRequest::~GLSLVertexBufferByteIndicesRequest()
    {
        delete m_indices;
    }
    
    GLsizei GLSLVertexBufferByteIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferByteIndicesRequest::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributes();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferRequest
    
    GLSLVertexBufferRequest::GLSLVertexBufferRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer): GLSLDrawRequest(pProgramInitializer), m_vertexBuffer(pVertexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferRequest::GetVerticesCount() const
    {
        return m_vertexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexBufferRequest::PerformDrawing() const
    {
        m_vertexBuffer->Bind();
        
        GetProgramInitializer()->InitializeAttributes();
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferRequest
    
    GLSLVertexArrayIndexBufferRequest::GLSLVertexArrayIndexBufferRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer): GLSLDrawRequest(pProgramInitializer), m_indexBuffer(pIndexBuffer)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayIndexBufferRequest::~GLSLVertexArrayIndexBufferRequest()
    {
        delete m_vertexArray;
    }
    
    GLsizei GLSLVertexArrayIndexBufferRequest::GetVerticesCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayIndexBufferRequest::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
        
        GetProgramInitializer()->InitializeAttributes(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesRequest
    
    GLSLVertexArrayShortIndicesRequest::GLSLVertexArrayShortIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices): GLSLDrawRequest(pProgramInitializer)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayShortIndicesRequest::~GLSLVertexArrayShortIndicesRequest()
    {
        delete m_vertexArray;
        delete m_indices;
    }
    
    GLsizei GLSLVertexArrayShortIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayShortIndicesRequest::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributes(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesRequest
    
    GLSLVertexArrayByteIndicesRequest::GLSLVertexArrayByteIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices): GLSLDrawRequest(pProgramInitializer)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayByteIndicesRequest::~GLSLVertexArrayByteIndicesRequest()
    {
        delete m_vertexArray;
        delete m_indices;
    }
    
    GLsizei GLSLVertexArrayByteIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayByteIndicesRequest::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributes(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
#pragma mark - GLSLVertexArrayRequest
    
    GLSLVertexArrayRequest::GLSLVertexArrayRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray): GLSLDrawRequest(pProgramInitializer)
    {
        m_vertexArray = new GLSLVertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    GLSLVertexArrayRequest::~GLSLVertexArrayRequest()
    {
        delete m_vertexArray;
    }
    
    GLsizei GLSLVertexArrayRequest::GetVerticesCount() const
    {
        return m_vertexArray->GetVerticesCount();
    }
    
    // TODO: Probably all PerformDrawing() methods can be refactored to eliminate duplicated code
    void GLSLVertexArrayRequest::PerformDrawing() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        
        GetProgramInitializer()->InitializeAttributes(m_vertexArray);
        GetProgramInitializer()->InitializeUniforms();
        
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
#pragma mark - GLSLRawVertexDataArraysIndexBufferRequest
    
#pragma mark - GLSLRawVertexDataArraysRawShortIndicesRequest
    
#pragma mark - GLSLRawVertexDataArraysRawByteIndicesRequest
    
#pragma mark - GLSLRawVertexDataArraysRequest
    
}