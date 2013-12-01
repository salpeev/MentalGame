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

#include <iostream>
using namespace std;



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
    
    GLSLDrawing::GLSLDrawing(): m_program(NULL), m_vertexBuffer(NULL), m_indexBuffer(NULL), m_rawElementsCount(0)
    {
        
    }
    
    GLSLDrawing::~GLSLDrawing()
    {
        delete m_program;
    }
    
#pragma mark - Public Methods
    
    void GLSLDrawing::Initialize()
    {
        GenerateProgram();
    }
    
    void GLSLDrawing::Draw() const
    {
        m_program->Use();
        
        if (m_vertexBuffer && m_indexBuffer)
        {
            m_vertexBuffer->Bind();
            m_indexBuffer->Bind();
            
            GLuint elementsCount = m_indexBuffer->GetElementsCount();
            glDrawElements(GL_LINES, elementsCount, GL_UNSIGNED_SHORT, NULL);       // TODO: check indices pointer
        }
        else if (m_vertexBuffer)
        {
            m_vertexBuffer->Bind();
//            GLSLIndexBuffer::UnbindCurrentBuffer();         // Should be disabled or not (for better performance)?
            
            GLuint elementsCount = m_vertexBuffer->GetElementsCount();
            glDrawArrays(GL_LINES, 0, elementsCount);
        }
        else if (m_rawElementsCount > 0)
        {
            GLSLVertexBuffer::UnbindCurrentBuffer();
            GLSLIndexBuffer::UnbindCurrentBuffer();
            
            glDrawArrays(GL_LINES, 0, m_rawElementsCount);
        }
    }
    
    void GLSLDrawing::UseVertexBufferWithIndexBuffer(GLRenderer::GLSLVertexBuffer *pVertexBuffer, GLRenderer::GLSLIndexBuffer *pIndexBuffer)
    {
        m_vertexBuffer = pVertexBuffer;
        m_indexBuffer = pIndexBuffer;
        m_rawElementsCount = 0;
        
        m_vertexBuffer->Bind();
        m_indexBuffer->Bind();
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseVertexBufferWithIndices(GLRenderer::GLSLVertexBuffer *pVertexBuffer, vector<GLushort> *pIndices)
    {
        
    }
    
    void GLSLDrawing::UseVertexBufferWithIndices(GLRenderer::GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> *pIndices)
    {
        
    }
    
    void GLSLDrawing::UseVertexBuffer(GLRenderer::GLSLVertexBuffer *pVertexBuffer)
    {
        m_vertexBuffer = pVertexBuffer;
        m_indexBuffer = NULL;
        m_rawElementsCount = 0;
        
        m_vertexBuffer->Bind();
//        GLSLIndexBuffer::UnbindCurrentBuffer();         // Should be disabled or not (for better performance)?
        
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::UseRawVertexData(GLvoid *pVertexData, GLuint elementsCount)
    {
        m_vertexBuffer = NULL;
        m_indexBuffer = NULL;
        m_rawElementsCount = elementsCount;
        
        GLSLVertexBuffer::UnbindCurrentBuffer();
//        GLSLIndexBuffer::UnbindCurrentBuffer();         // Should be disabled or not (for better performance)?
        
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
}