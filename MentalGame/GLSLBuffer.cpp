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
    
    GLenum GLSLBuffer::OpenGLESUsageFromBufferUsage(GLSL_BUFFER_USAGE usage) const
    {
        switch (usage) {
            case GLSL_BUFFER_USAGE_STREAM_DRAW: return GL_STREAM_DRAW;
            case GLSL_BUFFER_USAGE_STATIC_DRAW: return GL_STATIC_DRAW;
            case GLSL_BUFFER_USAGE_DYNAMIC_DRAW: return GL_DYNAMIC_DRAW;
        }
    }
}