//
//  VertexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Buffer.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class VertexBuffer : public Buffer {
    public:
        void LoadBufferData(const vector<float> &rBufferData, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        void LoadBufferData(const GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        void LoadBufferSubData(const GLvoid *bufferData, GLintptr offset, GLsizeiptr size) const;
        
        GLSL_BUFFER TargetBuffer() const;
        GET_PARAMETER BufferBindingParameter() const;
        
        static void UnbindCurrentBuffer();
    };
}
