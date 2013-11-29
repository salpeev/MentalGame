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