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
        ~GLSLBuffer();
        
        GLsizei GetElementsCount() const;
        
        void Bind() const;
        void Unbind() const;
        void LoadVertexData(GLvoid *vertexData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        virtual GLSL_BUFFER TargetBuffer() const = 0;
        
    protected:
        void SetElementsCount(GLuint elementsCount);
        GLenum OpenGLTargetBuffer() const;
        
    protected:
        GLuint m_bufferHandle;
        GLsizei m_elementsCount;
    };
}
