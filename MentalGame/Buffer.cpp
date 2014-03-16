//
//  Buffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Buffer.h"
#include "Logger.h"



namespace Renderer {
    
    Buffer::Buffer(): m_elementsCount(0), m_elementSize(0) {
        glGenBuffers(1, &m_bufferHandle);
        CheckError();
    }
    
    Buffer::~Buffer() {
        glDeleteBuffers(1, &m_bufferHandle);
        CheckError();
    }
    
#pragma mark - Public Methods
    
    GLuint Buffer::GetElementsCount() const {
        return m_elementsCount;
    }
    
    GLsizei Buffer::GetElementSize() const {
        return m_elementSize;
    }
    
    void Buffer::Bind() const {
        if (!IsBound()) {
            GLSL_BUFFER targetBuffer = TargetBuffer();
            glBindBuffer(targetBuffer, m_bufferHandle);
            CheckError();
        }
    }
    
    bool Buffer::IsBound() const {
        GET_PARAMETER getParameter = BufferBindingParameter();
        
        GLint boundBufferHandle;
        glGetIntegerv(getParameter, &boundBufferHandle);
        CheckError();
        
        bool bound = (boundBufferHandle == m_bufferHandle);
        return bound;
    }
    
#pragma mark - Protected methods
    
    void Buffer::LoadBufferData(const GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage) {
        SetElementsCount(elementsCount);
        SetElementSize(elementSize);
        
        Bind();
        
        GLSL_BUFFER targetBuffer = TargetBuffer();
        GLfloat dataSize = elementSize * elementsCount;
        glBufferData(targetBuffer, dataSize, bufferData, usage);
        CheckError();
    }
    
    void Buffer::LoadBufferSubData(const GLvoid *bufferData, GLintptr offset, GLsizeiptr size) const {
        // TODO: Check correctness
        Bind();
        
        GLSL_BUFFER targetBuffer = TargetBuffer();
        glBufferSubData(targetBuffer, offset, size, bufferData);
        CheckError();
    }
    
#pragma mark - Private Methods
    
    void Buffer::SetElementsCount(GLuint elementsCount) {
        m_elementsCount = elementsCount;
    }
    
    void Buffer::SetElementSize(GLsizei elementSize) {
        m_elementSize = elementSize;
    }
}