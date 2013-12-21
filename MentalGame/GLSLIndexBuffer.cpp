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
    void GLSLIndexBuffer::LoadBufferData(vector<GLushort> &rBufferData, GLSL_BUFFER_USAGE usage)
    {
        m_dataType = GLSL_DATA_TYPE_UNSIGNED_SHORT;
        // TODO: What happens if elements count is 0?
        GLSLBuffer::LoadBufferData(&rBufferData[0], sizeof(rBufferData[0]), rBufferData.size(), usage);
    }
    
    void GLSLIndexBuffer::LoadBufferData(vector<GLubyte> &rBufferData, GLSL_BUFFER_USAGE usage)
    {
        m_dataType = GLSL_DATA_TYPE_UNSIGNED_BYTE;
        // TODO: What happens if elements count is 0?
        GLSLBuffer::LoadBufferData(&rBufferData[0], sizeof(rBufferData[0]), rBufferData.size(), usage);
    }
    
    GLSL_DATA_TYPE GLSLIndexBuffer::GetDataType() const
    {
        return m_dataType;
    }
    
    GLSL_BUFFER GLSLIndexBuffer::TargetBuffer() const
    {
        return GLSL_ELEMENT_ARRAY_BUFFER;
    }
    
    GLSL_GET_PARAMETER GLSLIndexBuffer::BufferBindingParameter() const
    {
        return GLSL_GET_PARAMETER_ELEMENT_ARRAY_BUFFER_BINDING;
    }
    
    void GLSLIndexBuffer::UnbindCurrentBuffer()
    {
        GLint boundBufferHandle;
        glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &boundBufferHandle);
        CheckError();
        
        if (boundBufferHandle != 0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            CheckError();
        }
    }
}