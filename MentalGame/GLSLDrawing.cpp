//
//  GLSLDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawing.h"
#include "GLSLProgram.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLResourceManager.h"



namespace GLRenderer
{
    
#pragma mark - Lifecycle
    
    GLSLDrawing::GLSLDrawing(): m_program(NULL), m_drawingState(NULL)
    {
        
    }
    
    GLSLDrawing::~GLSLDrawing()
    {
        delete m_program;
        delete m_drawingState;
    }
    
#pragma mark - Public Methods
    
    void GLSLDrawing::Draw() const
    {
        m_program->Use();
        m_drawingState->PerformDrawing();
    }
    
    void GLSLDrawing::SetRenderMode(GLSL_RENDER_MODE renderMode)
    {
        m_drawingState->SetRenderMode(renderMode);
    }
    
    void GLSLDrawing::SetStartDrawIndex(GLint startDrawIndex)
    {
        m_drawingState->SetStartDrawIndex(startDrawIndex);
    }
    
    GLint GLSLDrawing::GetStartDrawIndex() const
    {
        return m_drawingState->GetStartDrawIndex();
    }
    
    void GLSLDrawing::SetDrawElementsCount(GLsizei drawCount)
    {
        m_drawingState->SetDrawElementsCount(drawCount);
    }
    
    GLsizei GLSLDrawing::GetDrawElementsCount() const
    {
        return m_drawingState->GetDrawElementsCount();
    }
    
    void GLSLDrawing::ResetStartDrawIndex()
    {
        m_drawingState->ResetStartDrawIndex();
    }
    
    void GLSLDrawing::ResetDrawElementsCount()
    {
        m_drawingState->ResetDrawCount();
    }
    
    void GLSLDrawing::ResetStartDrawIndexAndDrawElementsCount()
    {
        m_drawingState->ResetStartDrawIndexAndDrawElementsCount();
    }
    
    void GLSLDrawing::UseVertexBufferWithIndexBuffer(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer)
    {
        GLSLVertexBufferIndexBufferState *pDrawingState = new GLSLVertexBufferIndexBufferState(pVertexBuffer, pIndexBuffer, this);
        SetDrawingState(pDrawingState);
    }
    
    void GLSLDrawing::UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices)
    {
        GLSLVertexBufferShortIndicesState *pDrawingState = new GLSLVertexBufferShortIndicesState(pVertexBuffer, rIndices, this);
        SetDrawingState(pDrawingState);
    }
    
    void GLSLDrawing::UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices)
    {
        GLSLVertexBufferByteIndicesState *pDrawingState = new GLSLVertexBufferByteIndicesState(pVertexBuffer, rIndices, this);
        SetDrawingState(pDrawingState);
    }
    
    void GLSLDrawing::UseVertexBuffer(GLSLVertexBuffer *pVertexBuffer)
    {
        GLSLVertexBufferState *pDrawingState = new GLSLVertexBufferState(pVertexBuffer, this);
        SetDrawingState(pDrawingState);
    }
    
    void GLSLDrawing::UseRawVertexDataWithIndexBuffer(GLvoid *pVertexData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer)
    {
        GLSLRawVertexDataIndexBufferState *pDrawingState = new GLSLRawVertexDataIndexBufferState(pVertexData, dataSize, pIndexBuffer, this);
        SetDrawingState(pDrawingState);
    }
    
    void GLSLDrawing::UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLushort> &rIndices)
    {
        GLSLRawVertexDataRawShortIndicesState *pDrawingState = new GLSLRawVertexDataRawShortIndicesState(pVertexData, dataSize, rIndices, this);
        SetDrawingState(pDrawingState);
    }
    
    void GLSLDrawing::UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLubyte> &rIndices)
    {
        GLSLRawVertexDataRawByteIndicesState *pDrawingState = new GLSLRawVertexDataRawByteIndicesState(pVertexData, dataSize, rIndices, this);
        SetDrawingState(pDrawingState);
    }
    
    void GLSLDrawing::UseRawVertexData(GLvoid *pVertexData, GLsizei elementSize, GLuint elementsCount)
    {
        GLSLRawVertexDataState *pDrawingState = new GLSLRawVertexDataState(pVertexData, elementSize, elementsCount, this);
        SetDrawingState(pDrawingState);
    }
    
#pragma mark - GLSLDrawingStateDelegate
    
    void GLSLDrawing::PerformAttributesInitialization(GLvoid *pData) const
    {
        InitializeAttributes(pData);
    }
    
#pragma mark - Protected Methods
    
    GLSLAttribute * GLSLDrawing::GetAttributeByName(string attributeName) const
    {
        GLSLAttribute *attribute = m_program->GetAttributeByName(attributeName);
        return attribute;
    }
    
    GLSLUniform * GLSLDrawing::GetUniformByName(string uniformName) const
    {
        GLSLUniform *uniform = m_program->GetUniformByName(uniformName);
        return uniform;
    }
    
    void GLSLDrawing::InitializeUniforms() const
    {
        
    }
    
#pragma mark - Private Methods
    
    void GLSLDrawing::GenerateProgram()
    {
        string vertexShaderSource = VertexShaderSource();
        string fragmentShaderSource = FragmentShaderSource();
        
        GLSLProgram *pProgram = new GLSLProgram(vertexShaderSource, fragmentShaderSource);
        pProgram->Use();
        SetProgram(pProgram);
        
        InitializeUniforms();
    }
    
    void GLSLDrawing::GenerateProgramIfNeeded()
    {
        if (m_program == NULL)
        {
            GenerateProgram();
        }
    }
    
    void GLSLDrawing::SetProgram(GLSLProgram *pProgram)
    {
        delete m_program;
        m_program = pProgram;
    }
    
    GLSLProgram * GLSLDrawing::GetProgram() const
    {
        return m_program;
    }
    
    void GLSLDrawing::SetDrawingState(GLRenderer::GLSLDrawingState *pDrawingState)
    {
        delete m_drawingState;
        m_drawingState = pDrawingState;
        
        GenerateProgramIfNeeded();
    }
}