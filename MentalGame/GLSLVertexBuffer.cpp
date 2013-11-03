//
//  GLSLVertexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertexBuffer.h"
#include "GLLogger.h"



namespace GLRenderer
{
    GLSLVertexBuffer::GLSLVertexBuffer()
    {
        
    }
    
    GLSLVertexBuffer::~GLSLVertexBuffer()
    {
        
    }
    
    void GLSLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_bufferHandle);
        CheckError();
    }
    
    void GLSLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        CheckError();
    }
    
    void GLSLVertexBuffer::LoadVertexData(GLvoid *vertexData, GLsizei dataSize, GLSL_BUFFER_USAGE usage) const
    {
        GLenum openGLUsage = OpenGLESUsageFromBufferUsage(usage);
        
        glBufferData(GL_ARRAY_BUFFER, dataSize, vertexData, openGLUsage);
        CheckError();
    }
}