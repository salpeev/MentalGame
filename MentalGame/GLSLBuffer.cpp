//
//  GLSLVertexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLBuffer.h"
#include "GLLogger.h"



namespace GLRenderer
{
    GLSLBuffer::GLSLBuffer()
    {
        glGenBuffers(1, &m_bufferHandle);
        CheckError();
    }
    
    GLSLBuffer::~GLSLBuffer()
    {
        glDeleteBuffers(1, &m_bufferHandle);
        CheckError();
    }
    
#pragma mark - Public Methods
    
    GLsizei GLSLBuffer::GetElementsCount() const
    {
        return m_elementsCount;
    }
    
#pragma mark - Protected methods
    
    void GLSLBuffer::SetElementsCount(GLuint elementsCount)
    {
        m_elementsCount = elementsCount;
    }
}