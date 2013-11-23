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
#include "GLResourceManager.h"

#include <iostream>
using namespace std;



namespace GLRenderer
{
#pragma mark - Lifecycle
    
    GLSLDrawing::GLSLDrawing(): m_program(NULL), m_vertexBuffer(NULL)
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
        InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::Draw() const
    {
        m_program->Use();
        m_vertexBuffer->Bind();
        
        GLuint elementsCount = m_vertexBuffer->GetElementsCount();
        glDrawArrays(GL_LINES, 0, elementsCount);
        
        m_vertexBuffer->Unbind();
    }
    
    void GLSLDrawing::SetVertexBuffer(GLSLVertexBuffer *pVertexBuffer)
    {
        m_vertexBuffer = pVertexBuffer;
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