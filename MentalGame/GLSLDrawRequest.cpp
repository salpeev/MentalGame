//
//  GLSLDrawRequest.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawRequest.h"
#include "GLLogger.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLSLVertexArray.h"
#include "GLSLAttributeInitializer.h"
#include "GLSLUniformInitializer.h"
#include <stdlib.h>



namespace Renderer
{
    
#pragma mark - GLSLDrawRequest
    
    GLSLDrawRequest::GLSLDrawRequest(): m_attributeInitializer(NULL), m_uniformInitalizer(NULL), m_renderMode(GLSL_RENDER_MODE_LINES), m_startDrawIndex(0), m_drawElementsCount(0)
    {
        
    }
    
    GLSLDrawRequest::~GLSLDrawRequest()
    {
        
    }
    
#pragma mark Public Methods
    
    void GLSLDrawRequest::SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer)
    {
        m_attributeInitializer = pAttributeInitializer;
    }
    
    void GLSLDrawRequest::SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer)
    {
        m_uniformInitalizer = pUniformInitializer;
    }
    
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
    
    GLSLAttributeInitializer * GLSLDrawRequest::GetAttributeInitializer() const
    {
        return m_attributeInitializer;
    }
    
    GLSLUniformInitializer * GLSLDrawRequest::GetUniformInitializer() const
    {
        return m_uniformInitalizer;
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
    
    void GLSLDrawRequest::Draw(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        Activate();
        Initialize(pAttributes, pUniforms);
        Draw();
    }
    
    
    
#pragma mark - GLSLDrawingVertexBufferIndexBufferRequest
    
    GLSLVertexBufferIndexBufferRequest::GLSLVertexBufferIndexBufferRequest(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer): m_vertexBuffer(pVertexBuffer), m_indexBuffer(pIndexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferIndexBufferRequest::GetVerticesCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    void GLSLVertexBufferIndexBufferRequest::Activate() const
    {
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
    }
    
    void GLSLVertexBufferIndexBufferRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexBufferIndexBufferRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesRequest
    
    GLSLVertexBufferShortIndicesRequest::GLSLVertexBufferShortIndicesRequest(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices): m_vertexBuffer(pVertexBuffer)
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
    
    void GLSLVertexBufferShortIndicesRequest::Activate() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexBufferShortIndicesRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexBufferShortIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesRequest
    
    GLSLVertexBufferByteIndicesRequest::GLSLVertexBufferByteIndicesRequest(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices): m_vertexBuffer(pVertexBuffer)
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
    
    void GLSLVertexBufferByteIndicesRequest::Activate() const
    {
        m_vertexBuffer->Bind();
        GLSLIndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexBufferByteIndicesRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexBufferByteIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexBufferRequest
    
    GLSLVertexBufferRequest::GLSLVertexBufferRequest(GLSLVertexBuffer *pVertexBuffer): m_vertexBuffer(pVertexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei GLSLVertexBufferRequest::GetVerticesCount() const
    {
        return m_vertexBuffer->GetElementsCount();
    }
    
    void GLSLVertexBufferRequest::Activate() const
    {
        m_vertexBuffer->Bind();
    }
    
    void GLSLVertexBufferRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexBufferRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferRequest
    
    GLSLVertexArrayIndexBufferRequest::GLSLVertexArrayIndexBufferRequest(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer): m_indexBuffer(pIndexBuffer)
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
    
    void GLSLVertexArrayIndexBufferRequest::Activate() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
    }
    
    void GLSLVertexArrayIndexBufferRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArray);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArrayIndexBufferRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesRequest
    
    GLSLVertexArrayShortIndicesRequest::GLSLVertexArrayShortIndicesRequest(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices)
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
    
    void GLSLVertexArrayShortIndicesRequest::Activate() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArrayShortIndicesRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArray);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArrayShortIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesRequest
    
    GLSLVertexArrayByteIndicesRequest::GLSLVertexArrayByteIndicesRequest(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices)
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
    
    void GLSLVertexArrayByteIndicesRequest::Activate() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArrayByteIndicesRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArray);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArrayByteIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
#pragma mark - GLSLVertexArrayRequest
    
    GLSLVertexArrayRequest::GLSLVertexArrayRequest(GLSLVertexArray &rVertexArray)
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
    
    void GLSLVertexArrayRequest::Activate() const
    {
        GLSLVertexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArrayRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        GLSLUniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArray);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArrayRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
#pragma mark - GLSLVertexArraysIndexBufferRequest
    
    GLSLVertexArraysIndexBufferRequest::GLSLVertexArraysIndexBufferRequest(vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer) {
        
    }
    
    GLSLVertexArraysIndexBufferRequest::~GLSLVertexArraysIndexBufferRequest() {
        
    }
    
    GLsizei GLSLVertexArraysIndexBufferRequest::GetVerticesCount() const {
        return 0;
    }
    
    void GLSLVertexArraysIndexBufferRequest::Activate() const {
        
    }
    
    void GLSLVertexArraysIndexBufferRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const {
        
    }
    
    void GLSLVertexArraysIndexBufferRequest::Draw() const {
        
    }
    
#pragma mark - GLSLVertexArraysShortIndicesRequest
    
    GLSLVertexArraysShortIndicesRequest::GLSLVertexArraysShortIndicesRequest(vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices) {
        
    }
    
    GLSLVertexArraysShortIndicesRequest::~GLSLVertexArraysShortIndicesRequest() {
        
    }
    
    GLsizei GLSLVertexArraysShortIndicesRequest::GetVerticesCount() const {
        return 0;
    }
    
    void GLSLVertexArraysShortIndicesRequest::Activate() const {
        
    }
    
    void GLSLVertexArraysShortIndicesRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const {
        
    }
    
    void GLSLVertexArraysShortIndicesRequest::Draw() const {
        
    }
    
#pragma mark - GLSLVertexArraysByteIndicesRequest
    
    GLSLVertexArraysByteIndicesRequest::GLSLVertexArraysByteIndicesRequest(vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices) {
        
    }
    
    GLSLVertexArraysByteIndicesRequest::~GLSLVertexArraysByteIndicesRequest() {
        
    }
    
    GLsizei GLSLVertexArraysByteIndicesRequest::GetVerticesCount() const {
        return 0;
    }
    
    void GLSLVertexArraysByteIndicesRequest::Activate() const {
        
    }
    
    void GLSLVertexArraysByteIndicesRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const {
        
    }
    
    void GLSLVertexArraysByteIndicesRequest::Draw() const {
        
    }
    
#pragma mark - GLSLVertexArraysRequest
    
    GLSLVertexArraysRequest::GLSLVertexArraysRequest(vector<GLSLVertexArray *> &rVertexArrays) {
        
    }
    
    GLSLVertexArraysRequest::~GLSLVertexArraysRequest() {
        
    }
    
    GLsizei GLSLVertexArraysRequest::GetVerticesCount() const {
        return 0;
    }
    
    void GLSLVertexArraysRequest::Activate() const {
        
    }
    
    void GLSLVertexArraysRequest::Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const {
        
    }
    
    void GLSLVertexArraysRequest::Draw() const {
        
    }
}