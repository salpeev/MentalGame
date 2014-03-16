//
//  VertexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "VertexBuffer.h"
#include "Logger.h"



namespace Renderer {
    
    void VertexBuffer::LoadBufferData(const vector<float> &rBufferData, GLSL_BUFFER_USAGE usage) {
        // TODO: What happens if elements count is 0?
        Buffer::LoadBufferData(&rBufferData[0], sizeof(rBufferData[0]), rBufferData.size(), usage);
    }
    
    void VertexBuffer::LoadBufferData(const GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage) {
        Buffer::LoadBufferData(bufferData, elementSize, elementsCount, usage);
    }
    
    void VertexBuffer::LoadBufferSubData(const GLvoid *bufferData, GLintptr offset, GLsizeiptr size) const {
        Buffer::LoadBufferSubData(bufferData, offset, size);
    }
    
    GLSL_BUFFER VertexBuffer::TargetBuffer() const {
        return GLSL_ARRAY_BUFFER;
    }
    
    GET_PARAMETER VertexBuffer::BufferBindingParameter() const {
        return GET_PARAMETER_ARRAY_BUFFER_BINDING;
    }
    
    void VertexBuffer::UnbindCurrentBuffer() {
        GLint boundBufferHandle;
        glGetIntegerv(GET_PARAMETER_ARRAY_BUFFER_BINDING, &boundBufferHandle);
        CheckError();
        
        if (boundBufferHandle != 0) {
            glBindBuffer(GLSL_ARRAY_BUFFER, 0);
            CheckError();
        }
    }
}