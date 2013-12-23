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
    GLSLBuffer::GLSLBuffer(): m_elementsCount(0), m_elementSize(0)
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
    
    GLuint GLSLBuffer::GetElementsCount() const
    {
        return m_elementsCount;
    }
    
    GLsizei GLSLBuffer::GetElementSize() const
    {
        return m_elementSize;
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
    
    void GLSLBuffer::LoadBufferData(GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage)
    {
        SetElementsCount(elementsCount);
        SetElementSize(elementSize);
        
        GLenum openGLTargetBuffer = OpenGLTargetBuffer();
        GLfloat dataSize = elementSize * elementsCount;
        GLenum openGLUsage = GLDataConverter::OpenGLESUsageFromBufferUsage(usage);
        
        Bind();
        
        glBufferData(openGLTargetBuffer, dataSize, bufferData, openGLUsage);
        CheckError();
    }
    
#pragma mark - Private Methods
    
    void GLSLBuffer::SetElementsCount(GLuint elementsCount)
    {
        m_elementsCount = elementsCount;
    }
    
    void GLSLBuffer::SetElementSize(GLsizei elementSize)
    {
        m_elementSize = elementSize;
    }
    
    GLenum GLSLBuffer::OpenGLTargetBuffer() const
    {
        GLSL_BUFFER targetBuffer = TargetBuffer();
        GLenum openGLBuffer = GLDataConverter::OpenGLESBufferFromBuffer(targetBuffer);
        return openGLBuffer;
    }
}