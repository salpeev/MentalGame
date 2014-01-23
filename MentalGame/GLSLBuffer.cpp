//
//  GLSLVertexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLBuffer.h"
#include "GLLogger.h"



namespace Renderer
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
            GLSL_BUFFER targetBuffer = TargetBuffer();
            glBindBuffer(targetBuffer, m_bufferHandle);
            CheckError();
        }
    }
    
    bool GLSLBuffer::IsBound() const
    {
        GLSL_GET getParameter = BufferBindingParameter();
        
        GLint boundBufferHandle;
        glGetIntegerv(getParameter, &boundBufferHandle);
        CheckError();
        
        bool bound = (boundBufferHandle == m_bufferHandle);
        return bound;
    }
    
#pragma mark - Protected methods
    
    void GLSLBuffer::LoadBufferData(GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage)
    {
        SetElementsCount(elementsCount);
        SetElementSize(elementSize);
        
        GLSL_BUFFER targetBuffer = TargetBuffer();
        GLfloat dataSize = elementSize * elementsCount;
        
        Bind();
        
        glBufferData(targetBuffer, dataSize, bufferData, usage);
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
}