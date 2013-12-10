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
#include "GLSLDrawingState.h"



namespace GLRenderer
{
    enum GLSL_DRAWING_STATE
    {
        GLSL_DRAWING_STATE_VERTEX_BUFFER_INDEX_BUFFER,
        GLSL_DRAWING_STATE_VERTEX_BUFFER_RAW_USHORT_INDEX_DATA,
        GLSL_DRAWING_STATE_VERTEX_BUFFER_RAW_UBYTE_INDEX_DATA,
        GLSL_DRAWING_STATE_VERTEX_BUFFER,
        GLSL_DRAWING_STATE_RAW_VERTEX_DATA_INDEX_BUFFER,
        GLSL_DRAWING_STATE_RAW_VERTEX_DATA_RAW_USHORT_INDEX_DATA,
        GLSL_DRAWING_STATE_RAW_VERTEX_DATA_RAW_UBYTE_INDEX_DATA,
        GLSL_DRAWING_STATE_RAW_VERTEX_DATA
    };
    
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
    
    void GLSLDrawing::Initialize()
    {
        GenerateProgram();
    }
    
    void GLSLDrawing::Draw() const
    {
        m_program->Use();
        m_drawingState->PerformDrawing();
    }
    
    void GLSLDrawing::UseVertexBufferWithIndexBuffer(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer)
    {
        GLSLVertexBufferIndexBufferState *pDrawingState = new GLSLVertexBufferIndexBufferState(pVertexBuffer, pIndexBuffer);
        SetDrawingState(pDrawingState);
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices)
    {
        GLSLVertexBufferShortIndicesState *pDrawingState = new GLSLVertexBufferShortIndicesState(pVertexBuffer, rIndices);
        SetDrawingState(pDrawingState);
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices)
    {
        GLSLVertexBufferByteIndicesState *pDrawingState = new GLSLVertexBufferByteIndicesState(pVertexBuffer, rIndices);
        SetDrawingState(pDrawingState);
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseVertexBuffer(GLSLVertexBuffer *pVertexBuffer)
    {
        GLSLVertexBufferState *pDrawingState = new GLSLVertexBufferState(pVertexBuffer);
        SetDrawingState(pDrawingState);
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseRawVertexDataWithIndexBuffer(GLvoid *pVertexData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer)
    {
        GLSLRawVertexDataIndexBufferState *pDrawingState = new GLSLRawVertexDataIndexBufferState(pVertexData, dataSize, pIndexBuffer);
        SetDrawingState(pDrawingState);
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLushort> &rIndices)
    {
        GLSLRawVertexDataRawShortIndicesState *pDrawingState = new GLSLRawVertexDataRawShortIndicesState(pVertexData, dataSize, rIndices);
        SetDrawingState(pDrawingState);
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLubyte> &rIndices)
    {
        GLSLRawVertexDataRawByteIndicesState *pDrawingState = new GLSLRawVertexDataRawByteIndicesState(pVertexData, dataSize, rIndices);
        SetDrawingState(pDrawingState);
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseRawVertexData(GLvoid *pVertexData, GLsizei elementSize, GLuint elementsCount)
    {
        GLSLRawVertexDataState *pDrawingState = new GLSLRawVertexDataState(pVertexData, elementSize, elementsCount);
        SetDrawingState(pDrawingState);
        
        GLSLVertexBuffer::UnbindCurrentBuffer();
        GLSLIndexBuffer::UnbindCurrentBuffer();
        
        InitializeAttributes(m_program->GetAttributes(), pVertexData);
    }
    
#pragma mark - Private Methods
    
    void GLSLDrawing::GenerateProgram()
    {
        string vertexShaderSource = VertexShaderSource();
        string fragmentShaderSource = FragmentShaderSource();
        
        GLSLProgram *pProgram = new GLSLProgram(vertexShaderSource, fragmentShaderSource);
        SetProgram(pProgram);
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
    }
}