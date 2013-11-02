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
    
    void GLSLVertexBuffer::LoadVertexData(GLSLVertexData *pVertexData, GLSL_BUFFER_USAGE usage) const
    {
        GLenum openGLUsage = OpenGLESUsageFromBufferUsage(usage);
#warning Replase GLFloat with real type
        GLsizeiptr dataSize = pVertexData->GetDataCount() * sizeof(GLfloat);
        GLvoid *dataPointer = pVertexData->GetDataPointer();
        
        glBufferData(GL_ARRAY_BUFFER, dataSize, dataPointer, openGLUsage);
        CheckError();
    }
}