//
//  DrawRequest.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "DrawRequest.h"
#include "Logger.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "AttributeInitializer.h"
#include "UniformInitializer.h"
#include <stdlib.h>



namespace Renderer
{
    
#pragma mark - DrawRequest
    
    DrawRequest::DrawRequest(): m_attributeInitializer(NULL), m_uniformInitalizer(NULL), m_renderMode(GLSL_RENDER_MODE_LINES), m_startDrawIndex(0), m_drawElementsCount(0)
    {
        
    }
    
    DrawRequest::~DrawRequest()
    {
        
    }
    
#pragma mark Public Methods
    
    void DrawRequest::SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer)
    {
        m_attributeInitializer = pAttributeInitializer;
    }
    
    void DrawRequest::SetUniformInitializer(UniformInitializer *pUniformInitializer)
    {
        m_uniformInitalizer = pUniformInitializer;
    }
    
    void DrawRequest::SetRenderMode(GLSL_RENDER_MODE renderMode)
    {
        m_renderMode = renderMode;
    }
    
    void DrawRequest::SetStartDrawIndex(GLint startDrawIndex)
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
    
    void DrawRequest::SetDrawElementsCount(GLsizei drawElementsCount)
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
    
    GLSLAttributeInitializer * DrawRequest::GetAttributeInitializer() const
    {
        return m_attributeInitializer;
    }
    
    UniformInitializer * DrawRequest::GetUniformInitializer() const
    {
        return m_uniformInitalizer;
    }
    
    GLSL_RENDER_MODE DrawRequest::GetRenderMode() const
    {
        return m_renderMode;
    }
    
    GLint DrawRequest::GetStartDrawIndex() const
    {
        return m_startDrawIndex;
    }
    
    GLsizei DrawRequest::GetDrawElementsCount() const
    {
        return m_drawElementsCount;
    }
    
    void DrawRequest::ResetStartDrawIndex()
    {
        SetStartDrawIndex(0);
    }
    
    void DrawRequest::ResetDrawCount()
    {
        GLsizei drawCount = GetVerticesCount() - GetStartDrawIndex();
        SetDrawElementsCount(drawCount);
    }
    
    void DrawRequest::ResetStartDrawIndexAndDrawElementsCount()
    {
        ResetStartDrawIndex();
        ResetDrawCount();
    }
    
    void DrawRequest::Draw(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
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
    
    
    
#pragma mark - VertexArrayIndexBufferRequest
    
    VertexArrayIndexBufferRequest::VertexArrayIndexBufferRequest(VertexArray &rVertexArray, IndexBuffer *pIndexBuffer): m_indexBuffer(pIndexBuffer)
    {
        m_vertexArray = new VertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    VertexArrayIndexBufferRequest::~VertexArrayIndexBufferRequest()
    {
        delete m_vertexArray;
    }
    
    GLsizei VertexArrayIndexBufferRequest::GetVerticesCount() const
    {
        return m_indexBuffer->GetElementsCount();
    }
    
    void VertexArrayIndexBufferRequest::Activate() const
    {
        VertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
    }
    
    void VertexArrayIndexBufferRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
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
    
    void VertexArrayIndexBufferRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
    
    
#pragma mark - VertexArrayShortIndicesRequest
    
    VertexArrayShortIndicesRequest::VertexArrayShortIndicesRequest(VertexArray &rVertexArray, vector<GLushort> &rIndices)
    {
        m_vertexArray = new VertexArray(rVertexArray);
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    VertexArrayShortIndicesRequest::~VertexArrayShortIndicesRequest()
    {
        delete m_vertexArray;
        delete m_indices;
    }
    
    GLsizei VertexArrayShortIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    void VertexArrayShortIndicesRequest::Activate() const
    {
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexArrayShortIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
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
    
    void VertexArrayShortIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
    
    
#pragma mark - VertexArrayByteIndicesRequest
    
    VertexArrayByteIndicesRequest::VertexArrayByteIndicesRequest(VertexArray &rVertexArray, vector<GLubyte> &rIndices)
    {
        m_vertexArray = new VertexArray(rVertexArray);
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    VertexArrayByteIndicesRequest::~VertexArrayByteIndicesRequest()
    {
        delete m_vertexArray;
        delete m_indices;
    }
    
    GLsizei VertexArrayByteIndicesRequest::GetVerticesCount() const
    {
        return m_indices->size();
    }
    
    void VertexArrayByteIndicesRequest::Activate() const
    {
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexArrayByteIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
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
    
    void VertexArrayByteIndicesRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
    
#pragma mark - VertexArrayRequest
    
    VertexArrayRequest::VertexArrayRequest(VertexArray &rVertexArray)
    {
        m_vertexArray = new VertexArray(rVertexArray);
        
        ResetDrawCount();
    }
    
    VertexArrayRequest::~VertexArrayRequest()
    {
        delete m_vertexArray;
    }
    
    GLsizei VertexArrayRequest::GetVerticesCount() const
    {
        return m_vertexArray->GetVerticesCount();
    }
    
    void VertexArrayRequest::Activate() const
    {
        VertexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexArrayRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const
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
    
    void VertexArrayRequest::Draw() const
    {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
#pragma mark - VertexArraysIndexBufferRequest
    
    VertexArraysIndexBufferRequest::VertexArraysIndexBufferRequest(vector<VertexArray> &rVertexArrays, IndexBuffer *pIndexBuffer): m_indexBuffer(pIndexBuffer) {
        m_vertexArrays = new vector<VertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            VertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            VertexArray *pVertexArray = new VertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        ResetDrawCount();
    }
    
    VertexArraysIndexBufferRequest::~VertexArraysIndexBufferRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            VertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
        delete m_indexBuffer;
    }
    
    GLsizei VertexArraysIndexBufferRequest::GetVerticesCount() const {
        return m_indexBuffer->GetElementsCount();
    }
    
    void VertexArraysIndexBufferRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
        m_indexBuffer->Bind();
    }
    
    void VertexArraysIndexBufferRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexArraysIndexBufferRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLSL_DATA_TYPE dataType = m_indexBuffer->GetDataType();
        GLvoid *indicesOffset = (GLvoid *)(m_indexBuffer->GetElementSize() * GetStartDrawIndex());
        
        glDrawElements(renderMode, elementsCount, dataType, indicesOffset);
        CheckError();
    }
    
#pragma mark - VertexArraysShortIndicesRequest
    
    VertexArraysShortIndicesRequest::VertexArraysShortIndicesRequest(vector<VertexArray> &rVertexArrays, vector<GLushort> &rIndices) {
        m_vertexArrays = new vector<VertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            VertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            VertexArray *pVertexArray = new VertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        m_indices = new vector<GLushort>(rIndices);
        
        ResetDrawCount();
    }
    
    VertexArraysShortIndicesRequest::~VertexArraysShortIndicesRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            VertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
        delete m_indices;
    }
    
    GLsizei VertexArraysShortIndicesRequest::GetVerticesCount() const {
        return m_indices->size();
    }
    
    void VertexArraysShortIndicesRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexArraysShortIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexArraysShortIndicesRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_SHORT, pIndices);
        CheckError();
    }
    
#pragma mark - VertexArraysByteIndicesRequest
    
    VertexArraysByteIndicesRequest::VertexArraysByteIndicesRequest(vector<VertexArray> &rVertexArrays, vector<GLubyte> &rIndices) {
        m_vertexArrays = new vector<VertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            VertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            VertexArray *pVertexArray = new VertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        m_indices = new vector<GLubyte>(rIndices);
        
        ResetDrawCount();
    }
    
    VertexArraysByteIndicesRequest::~VertexArraysByteIndicesRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            VertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
        delete m_indices;
    }
    
    GLsizei VertexArraysByteIndicesRequest::GetVerticesCount() const {
        return m_indices->size();
    }
    
    void VertexArraysByteIndicesRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
        IndexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexArraysByteIndicesRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexArraysByteIndicesRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLuint elementsCount = GetDrawElementsCount();
        GLint startIndex = GetStartDrawIndex();
        GLvoid *pIndices = (GLvoid *)(&m_indices->at(startIndex));
        
        glDrawElements(renderMode, elementsCount, GLSL_DATA_TYPE_UNSIGNED_BYTE, pIndices);
        CheckError();
    }
    
#pragma mark - VertexArraysRequest
    
    VertexArraysRequest::VertexArraysRequest(vector<VertexArray> &rVertexArrays) {
        m_vertexArrays = new vector<VertexArray *>;
        for (int vertexArrayIndex = 0; vertexArrayIndex < rVertexArrays.size(); vertexArrayIndex++) {
            VertexArray vertexArray = rVertexArrays.at(vertexArrayIndex);
            VertexArray *pVertexArray = new VertexArray(vertexArray);
            m_vertexArrays->push_back(pVertexArray);
        }
        
        CalculateVerticesCount();
        ResetDrawCount();
    }
    
    VertexArraysRequest::~VertexArraysRequest() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            VertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            delete pVertexArray;
        }
        
        delete m_vertexArrays;
    }
    
    GLsizei VertexArraysRequest::GetVerticesCount() const {
        return m_verticesCount;
    }
    
    void VertexArraysRequest::Activate() const {
        VertexBuffer::UnbindCurrentBuffer();
    }
    
    void VertexArraysRequest::Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const {
        GLSLAttributeInitializer *pAttributeInitializer = GetAttributeInitializer();
        UniformInitializer *pUniformInitializer = GetUniformInitializer();
        
        if (pAttributeInitializer) {
            pAttributeInitializer->InitializeAttributes(pAttributes, m_vertexArrays);
        }
        
        if (pUniformInitializer) {
            pUniformInitializer->InitializeUniforms(pUniforms);
        }
    }
    
    void VertexArraysRequest::Draw() const {
        GLSL_RENDER_MODE renderMode = GetRenderMode();
        GLint startIndex = GetStartDrawIndex();
        GLuint elementsCount = GetDrawElementsCount();
        
        glDrawArrays(renderMode, startIndex, elementsCount);
        CheckError();
    }
    
    void VertexArraysRequest::CalculateVerticesCount() {
        for (int vertexArrayIndex = 0; vertexArrayIndex < m_vertexArrays->size(); vertexArrayIndex++) {
            VertexArray *pVertexArray = m_vertexArrays->at(vertexArrayIndex);
            
            if (vertexArrayIndex == 0) {
                m_verticesCount = pVertexArray->GetVerticesCount();
            } else if (pVertexArray->GetVerticesCount() < m_verticesCount) {
                m_verticesCount = pVertexArray->GetVerticesCount();
            }
        }
    }
}