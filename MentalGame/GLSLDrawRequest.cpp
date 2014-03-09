//
//  GLSLDrawRequest.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawRequest.h"
#include "GLLogger.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "GLSLVertexArray.h"
#include "AttributeInitializer.h"
#include "UniformInitializer.h"
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
    
    void GLSLDrawRequest::SetUniformInitializer(UniformInitializer *pUniformInitializer)
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
    
    UniformInitializer * GLSLDrawRequest::GetUniformInitializer() const
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
    
    void GLSLDrawRequest::Draw(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        Activate();
        Initialize(pAttributes, pUniforms);
        Draw();
    }
    
    
    
#pragma mark - GLSLDrawingVertexBufferIndexBufferRequest
    
    VertexBufferIndexBufferRequest::VertexBufferIndexBufferRequest(VertexBuffer *pVertexBuffer, IndexBuffer *pIndexBuffer): m_vertexBuffer(pVertexBuffer), m_indexBuffer(pIndexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei VertexBufferIndexBufferRequest::GetVerticesCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    void VertexBufferIndexBufferRequest::Activate() const
    {
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
    }
    
    void VertexBufferIndexBufferRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexBufferIndexBufferRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - VertexBufferShortIndicesRequest
    
    VertexBufferShortIndicesRequest::VertexBufferShortIndicesRequest(VertexBuffer *pVertexBuffer, vector<GLushort> &rIndices): m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    VertexBufferShortIndicesRequest::~VertexBufferShortIndicesRequest()
    {
        delete m_indices;
    }
    
    GLsizei VertexBufferShortIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    void VertexBufferShortIndicesRequest::Activate() const
    {
        m_vertexBuffer->Bind();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexBufferShortIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexBufferShortIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - VertexBufferByteIndicesRequest
    
    VertexBufferByteIndicesRequest::VertexBufferByteIndicesRequest(VertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices): m_vertexBuffer(pVertexBuffer)
    {
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    VertexBufferByteIndicesRequest::~VertexBufferByteIndicesRequest()
    {
        delete m_indices;
    }
    
    GLsizei VertexBufferByteIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    void VertexBufferByteIndicesRequest::Activate() const
    {
        m_vertexBuffer->Bind();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexBufferByteIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexBufferByteIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - VertexBufferRequest
    
    VertexBufferRequest::VertexBufferRequest(VertexBuffer *pVertexBuffer): m_vertexBuffer(pVertexBuffer)
    {
        ResetDrawCount();
    }
    
    GLsizei VertexBufferRequest::GetVerticesCount() const
    {
        return m_vertexBuffer->GetElementsCount();
    }
    
    void VertexBufferRequest::Activate() const
    {
        m_vertexBuffer->Bind();
    }
    
    void VertexBufferRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer)
        {
            pAttributeInitializer->InitializeAttributes(pAttributes);
        }
        
        if (pUniformInitializer)
        {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexBufferRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferRequest
    
    GLSLVertexArrayIndexBufferRequest::GLSLVertexArrayIndexBufferRequest(GLSLVertexArray &rVertexArray, IndexBuffer *pIndexBuffer): m_indexBuffer(pIndexBuffer)
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
        VertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
    }
    
    void GLSLVertexArrayIndexBufferRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
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
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArrayShortIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
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
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArrayByteIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
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
        VertexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArrayRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
    {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
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
    
    GLSLVertexArraysIndexBufferRequest::GLSLVertexArraysIndexBufferRequest(vector<GLSLVertexArray> &rVertexArrays, IndexBuffer *pIndexBuffer): m_indexBuffer(pIndexBuffer) {
        m_vertexArrays = new vector<GLSLVertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            GLSLVertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            GLSLVertexArray *pVertexArray = new GLSLVertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        ResetDrawCount();
    }
    
    GLSLVertexArraysIndexBufferRequest::~GLSLVertexArraysIndexBufferRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            GLSLVertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
        delete m_indexBuffer;
    }
    
    GLsizei GLSLVertexArraysIndexBufferRequest::GetVerticesCount() const {
        return m_indexBuffer->GetElementsCount();
    }
    
    void GLSLVertexArraysIndexBufferRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
    }
    
    void GLSLVertexArraysIndexBufferRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArraysIndexBufferRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
#pragma mark - GLSLVertexArraysShortIndicesRequest
    
    GLSLVertexArraysShortIndicesRequest::GLSLVertexArraysShortIndicesRequest(vector<GLSLVertexArray> &rVertexArrays, vector<GLushort> &rIndices) {
        m_vertexArrays = new vector<GLSLVertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            GLSLVertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            GLSLVertexArray *pVertexArray = new GLSLVertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexArraysShortIndicesRequest::~GLSLVertexArraysShortIndicesRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            GLSLVertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
        delete m_indices;
    }
    
    GLsizei GLSLVertexArraysShortIndicesRequest::GetVerticesCount() const {
        return m_indices->size();
    }
    
    void GLSLVertexArraysShortIndicesRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArraysShortIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArraysShortIndicesRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
#pragma mark - GLSLVertexArraysByteIndicesRequest
    
    GLSLVertexArraysByteIndicesRequest::GLSLVertexArraysByteIndicesRequest(vector<GLSLVertexArray> &rVertexArrays, vector<GLubyte> &rIndices) {
        m_vertexArrays = new vector<GLSLVertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            GLSLVertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            GLSLVertexArray *pVertexArray = new GLSLVertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    GLSLVertexArraysByteIndicesRequest::~GLSLVertexArraysByteIndicesRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            GLSLVertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
        delete m_indices;
    }
    
    GLsizei GLSLVertexArraysByteIndicesRequest::GetVerticesCount() const {
        return m_indices->size();
    }
    
    void GLSLVertexArraysByteIndicesRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArraysByteIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArraysByteIndicesRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
#pragma mark - GLSLVertexArraysRequest
    
    GLSLVertexArraysRequest::GLSLVertexArraysRequest(vector<GLSLVertexArray> &rVertexArrays) {
        m_vertexArrays = new vector<GLSLVertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            GLSLVertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            GLSLVertexArray *pVertexArray = new GLSLVertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        CalculateVerticesCount();
        ResetDrawCount();
    }
    
    GLSLVertexArraysRequest::~GLSLVertexArraysRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            GLSLVertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
    }
    
    GLsizei GLSLVertexArraysRequest::GetVerticesCount() const {
        return m_verticesCount;
    }
    
    void GLSLVertexArraysRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
    }
    
    void GLSLVertexArraysRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void GLSLVertexArraysRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
    void GLSLVertexArraysRequest::CalculateVerticesCount() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            GLSLVertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            
            if (vertexArrayIndex == 0) {
                m_verticesCount = pVertexArray->GetVerticesCount();
            } else if (pVertexArray->GetVerticesCount() < m_verticesCount) {
                m_verticesCount = pVertexArray->GetVerticesCount();
            }
        }
    }
}