//
//  GLSLIndexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLIndexBuffer.h"
#include "GLLogger.h"



namespace GLRenderer
{
    GLSLIndexBuffer::GLSLIndexBuffer()
    {
        
    }
    
    GLSLIndexBuffer::~GLSLIndexBuffer()
    {
        
    }
    
    void GLSLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferHandle);
        CheckError();
    }
    
    void GLSLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        CheckError();
    }
}