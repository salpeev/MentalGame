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
}