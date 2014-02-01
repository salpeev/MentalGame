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



namespace Renderer
{
    class GLSLBuffer
    {
    public:
        GLSLBuffer();
        GLSLBuffer(const GLSLBuffer &rBuffer) = delete;
        virtual ~GLSLBuffer();
        
        GLuint GetElementsCount() const;
        GLsizei GetElementSize() const;
        
        void Bind() const;
        bool IsBound() const;
        
        virtual GLSL_BUFFER TargetBuffer() const = 0;
        virtual GET_PARAMETER BufferBindingParameter() const = 0;
        
    protected:
        void LoadBufferData(GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        
    private:
        void SetElementsCount(GLuint elementsCount);
        void SetElementSize(GLsizei elementSize);
        
        GLuint m_bufferHandle;
        GLuint m_elementsCount;
        GLsizei m_elementSize;
    };
}
