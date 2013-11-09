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



namespace GLRenderer
{
    GLSLDrawing::GLSLDrawing(): m_program(NULL), m_vertexBuffer(NULL)
    {
        
    }
    
    GLSLDrawing::~GLSLDrawing()
    {
        delete m_program;
        delete m_vertexBuffer;
    }
    
    void GLSLDrawing::SetProgram(GLSLProgram *pProgram)
    {
        
    }
    
    GLSLProgram * GLSLDrawing::GetProgram() const
    {
        return NULL;
    }
    
    void GLSLDrawing::SetVertexBuffer(GLSLVertexBuffer *pVertexBuffer)
    {
        
    }
    
    GLSLVertexBuffer * GLSLDrawing::GetVertexBuffer() const
    {
        return NULL;
    }
}