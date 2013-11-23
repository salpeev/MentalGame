//
//  GLSLVertexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertexBuffer.h"
#include "GLLogger.h"
#include "GLDataConverter.h"



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
    
    void GLSLVertexBuffer::LoadVertexData(GLvoid *vertexData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage)
    {
        SetElementsCount(elementsCount);
        
        GLfloat dataSize = elementSize * elementsCount;
        GLenum openGLUsage = GLDataConverter::OpenGLESUsageFromBufferUsage(usage);
        
        Bind();
        
        glBufferData(GL_ARRAY_BUFFER, dataSize, vertexData, openGLUsage);
        CheckError();
        
        Unbind();
    }
}