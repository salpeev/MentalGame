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
    
#pragma mark - Protected Methods
    
    
    
#pragma mark - Private Methods
    
    void GLSLDrawing::GenerateProgram()
    {
        string vertexShaderSource = VertexShaderSource();
        string fragmentShaderSource = FragmentShaderSource();
        
        GLSLProgram *pProgram = new GLSLProgram(vertexShaderSource, fragmentShaderSource);
        pProgram->Use();
        SetProgram(pProgram);
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