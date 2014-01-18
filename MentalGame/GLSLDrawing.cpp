//
//  GLSLDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawing.h"
#include "GLSLProgram.h"



namespace GLRenderer
{
    
#pragma mark - Lifecycle
    
    GLSLDrawing::GLSLDrawing(): m_program(NULL)
    {
        
    }
    
    GLSLDrawing::~GLSLDrawing()
    {
        delete m_program;
    }
    
#pragma mark - Public Methods
    
    void GLSLDrawing::ExecuteDrawRequest(GLSLDrawRequest *pDrawRequest) const
    {
        m_program->Use();
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