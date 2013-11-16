//
//  GLSLIndexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLIndexBuffer.h"
#include "GLLogger.h"
#include "GLDataConverter.h"



namespace GLRenderer
{
    GLSLIndexBuffer::GLSLIndexBuffer()
    {
        
    }
    
    GLSLIndexBuffer::~GLSLIndexBuffer()
    {
        
    }
    
    void GLSLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferHandle);
        CheckError();
    }
    
    void GLSLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        CheckError();
    }
    
    void GLSLIndexBuffer::LoadVertexData(GLvoid *vertexData, GLsizei dataSize, GLSL_BUFFER_USAGE usage) const
    {
        GLenum openGLUsage = GLDataConverter::OpenGLESUsageFromBufferUsage(usage);
        
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, vertexData, openGLUsage);
        CheckError();
    }
}