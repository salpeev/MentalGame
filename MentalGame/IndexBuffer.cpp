//
//  IndexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "IndexBuffer.h"
#include "Logger.h"



namespace Renderer {
    
    void IndexBuffer::LoadBufferData(const vector<GLushort> &rBufferData, GLSL_BUFFER_USAGE usage) {
        m_dataType = DATA_TYPE_UNSIGNED_SHORT;
        // TODO: What happens if elements count is 0?
        Buffer::LoadBufferData(&rBufferData[0], sizeof(rBufferData[0]), rBufferData.size(), usage);
    }
    
    void IndexBuffer::LoadBufferData(const vector<GLubyte> &rBufferData, GLSL_BUFFER_USAGE usage) {
        m_dataType = DATA_TYPE_UNSIGNED_BYTE;
        // TODO: What happens if elements count is 0?
        Buffer::LoadBufferData(&rBufferData[0], sizeof(rBufferData[0]), rBufferData.size(), usage);
    }
    
    DATA_TYPE IndexBuffer::GetDataType() const {
        return m_dataType;
    }
    
    GLSL_BUFFER IndexBuffer::TargetBuffer() const {
        return GLSL_ELEMENT_ARRAY_BUFFER;
    }
    
    GET_PARAMETER IndexBuffer::BufferBindingParameter() const {
        return GET_PARAMETER_ELEMENT_ARRAY_BUFFER_BINDING;
    }
    
    void IndexBuffer::UnbindCurrentBuffer() {
        GLint boundBufferHandle;
        glGetIntegerv(GET_PARAMETER_ELEMENT_ARRAY_BUFFER_BINDING, &boundBufferHandle);
        CheckError();
        
        if (boundBufferHandle != 0) {
            glBindBuffer(GLSL_ELEMENT_ARRAY_BUFFER, 0);
            CheckError();
        }
    }
}