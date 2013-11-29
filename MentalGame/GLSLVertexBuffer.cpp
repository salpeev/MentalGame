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