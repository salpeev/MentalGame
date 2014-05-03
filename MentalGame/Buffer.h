//
//  Buffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenglES/ES2/gl.h>
#include "Constants.h"



namespace Renderer {
    
    class Buffer {
    public:
        Buffer();
        Buffer(const Buffer &rBuffer) = delete;
        virtual ~Buffer();
        
        GLuint GetElementsCount() const;
        GLsizei GetElementSize() const;
        
        void Bind() const;
        bool IsBound() const;
        
        virtual GLSL_BUFFER TargetBuffer() const = 0;
        virtual GET_PARAMETER BufferBindingParameter() const = 0;
        
    protected:
        virtual void LoadBufferData(const GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        virtual void LoadBufferSubData(const GLvoid *bufferData, GLintptr offset, GLsizeiptr size) const;
        
    private:
        void SetElementsCount(GLuint elementsCount);
        void SetElementSize(GLsizei elementSize);
        
        GLuint m_bufferHandle;
        GLuint m_elementsCount;
        GLsizei m_elementSize;
    };
}
