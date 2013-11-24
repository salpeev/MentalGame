//
//  GLSLVertexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLBuffer.h"
#include "GLLogger.h"
#include "GLDataConverter.h"



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
    
    void GLSLBuffer::Bind() const
    {
        if (!IsBound())
        {
            GLenum openGLTargetBuffer = OpenGLTargetBuffer();
            glBindBuffer(openGLTargetBuffer, m_bufferHandle);
            CheckError();
        }
    }
    
    void GLSLBuffer::LoadVertexData(GLvoid *vertexData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage)
    {
        SetElementsCount(elementsCount);
        
        GLenum openGLTargetBuffer = OpenGLTargetBuffer();
        GLfloat dataSize = elementSize * elementsCount;
        GLenum openGLUsage = GLDataConverter::OpenGLESUsageFromBufferUsage(usage);
        
        Bind();
        
        glBufferData(openGLTargetBuffer, dataSize, vertexData, openGLUsage);
        CheckError();
    }
    
    bool GLSLBuffer::IsBound() const
    {
        GLSL_GET_PARAMETER getParameter = BufferBindingParameter();
        GLenum openGLGetParameter = GLDataConverter::OpenGLESGetParameterFromGetParameter(getParameter);
        
        GLint boundBufferHandle;
        glGetIntegerv(openGLGetParameter, &boundBufferHandle);
        CheckError();
        
        bool bound = (boundBufferHandle == m_bufferHandle);
        return bound;
    }
    
#pragma mark - Protected methods
    
    void GLSLBuffer::SetElementsCount(GLuint elementsCount)
    {
        m_elementsCount = elementsCount;
    }
    
    GLenum GLSLBuffer::OpenGLTargetBuffer() const
    {
        GLSL_BUFFER targetBuffer = TargetBuffer();
        GLenum openGLBuffer = GLDataConverter::OpenGLESBufferFromBuffer(targetBuffer);
        return openGLBuffer;
    }
}