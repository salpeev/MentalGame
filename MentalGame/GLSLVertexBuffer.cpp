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
    void GLSLVertexBuffer::LoadBufferData(vector<float> &rBufferData, GLSL_BUFFER_USAGE usage)
    {
        // TODO: What happens if elements count is 0?
        GLSLBuffer::LoadBufferData(&rBufferData[0], sizeof(rBufferData[0]), rBufferData.size(), usage);
    }
    
    void GLSLVertexBuffer::LoadBufferData(GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage)
    {
        GLSLBuffer::LoadBufferData(bufferData, elementSize, elementsCount, usage);
    }
    
    GLSL_BUFFER GLSLVertexBuffer::TargetBuffer() const
    {
        return GLSL_ARRAY_BUFFER;
    }
    
    GLSL_GET_PARAMETER GLSLVertexBuffer::BufferBindingParameter() const
    {
        return GLSL_GET_PARAMETER_ARRAY_BUFFER_BINDING;
    }
    
    void GLSLVertexBuffer::UnbindCurrentBuffer()
    {
        GLint boundBufferHandle;
        glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &boundBufferHandle);
        CheckError();
        
        if (boundBufferHandle != 0)
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            CheckError();
        }
    }
}