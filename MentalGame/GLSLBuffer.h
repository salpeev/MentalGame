//
//  GLSLVertexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenglES/ES2/gl.h>
#include "GLConstants.h"



namespace GLRenderer
{
    class GLSLBuffer
    {
    public:
        GLSLBuffer();
        GLSLBuffer(const GLSLBuffer &rBuffer) = delete;
        ~GLSLBuffer();
        
        GLsizei GetElementsCount() const;
        
        void Bind() const;
        void LoadVertexData(GLvoid *vertexData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        bool IsBound() const;
        
        virtual GLSL_BUFFER TargetBuffer() const = 0;
        virtual GLSL_GET_PARAMETER BufferBindingParameter() const = 0;
        
    protected:
        void SetElementsCount(GLuint elementsCount);
        GLenum OpenGLTargetBuffer() const;
        
    protected:
        GLuint m_bufferHandle;
        GLsizei m_elementsCount;
    };
}
