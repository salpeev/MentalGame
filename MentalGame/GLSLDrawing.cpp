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
    
    GLSLDrawing::GLSLDrawing(): m_program(NULL), m_attributeInitializer(NULL), m_uniformInitializer(NULL), m_drawingState(NULL)
    {
        
    }
    
    GLSLDrawing::~GLSLDrawing()
    {
        delete m_program;
        delete m_drawingState;
    }
    
#pragma mark - Public Methods
    
    void GLSLDrawing::SetAttributeInitializer(GLSLAttributeInitializer *pAttributeinitializer)
    {
        m_attributeInitializer = pAttributeinitializer;
    }
    
    void GLSLDrawing::SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer)
    {
        m_uniformInitializer = pUniformInitializer;
    }
    
    void GLSLDrawing::SetDrawingState(GLRenderer::GLSLDrawingState *pDrawingState)
    {
        m_drawingState = pDrawingState;
        
        GenerateProgramIfNeeded();
    }
    
    GLSLAttributeInitializer * GLSLDrawing::GetAttributeInitializer() const
    {
        return m_attributeInitializer;
    }
    
    GLSLUniformInitializer * GLSLDrawing::GetUniformInitializer() const
    {
        return m_uniformInitializer;
    }
    
    GLSLDrawingState * GLSLDrawing::GetDrawingState() const
    {
        return m_drawingState;
    }
    
    void GLSLDrawing::Draw() const
    {
        m_program->Use();
        m_drawingState->PerformDrawing();
    }
    
#pragma mark - GLSLProgramInitializer
    
    void GLSLDrawing::InitializeAttributes() const
    {
        m_attributeInitializer->InitializeAttributes(m_program->GetAttributes());
    }
    
    void GLSLDrawing::InitializeAttributes(GLSLVertexArray *pVertexArray) const
    {
        m_attributeInitializer->InitializeAttributes(m_program->GetAttributes(), pVertexArray);
    }
    
    void GLSLDrawing::InitializeAttributes(vector<GLSLVertexArray *> *pVertexArrays) const
    {
        m_attributeInitializer->InitializeAttributes(m_program->GetAttributes(), pVertexArrays);
    }
    
    void GLSLDrawing::InitializeUniforms() const
    {
        m_uniformInitializer->InitializeUniforms(m_program->GetUniforms());
    }
    
#pragma mark - Private Methods
    
    void GLSLDrawing::GenerateProgram()
    {
        string vertexShaderSource = VertexShaderSource();
        string fragmentShaderSource = FragmentShaderSource();
        
        m_program = new GLSLProgram(vertexShaderSource, fragmentShaderSource);
    }
    
    void GLSLDrawing::GenerateProgramIfNeeded()
    {
        if (m_program == NULL)
        {
            GenerateProgram();
        }
    }
}