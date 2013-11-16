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
        delete m_vertexBuffer;
    }
    
#pragma mark - Public Methods
    
    void GLSLDrawing::Initialize()
    {
        GenerateProgram();
    }
    
    void GLSLDrawing::SetVertexBuffer(GLSLVertexBuffer *pVertexBuffer)
    {
        // TODO: Check ability to use copy constructor
        delete m_vertexBuffer;
        m_vertexBuffer = pVertexBuffer;
    }
    
    GLSLVertexBuffer * GLSLDrawing::GetVertexBuffer() const
    {
        return m_vertexBuffer;
    }
    
#pragma mark - Private Methods
    
    void GLSLDrawing::GenerateProgram()
    {
        string vertexShaderName = VertexShaderName();
        string fragmentShaderName = FragmentShaderName();
        
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed(vertexShaderName);
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed(fragmentShaderName);
        
        cout << vertexShaderSource << endl;
        cout << fragmentShaderSource << endl;
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