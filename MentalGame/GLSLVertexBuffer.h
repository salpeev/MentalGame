//
//  GLSLVertexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLBuffer.h"
#include <vector>

using namespace std;



namespace GLRenderer
{
    class GLSLVertexBuffer : public GLSLBuffer
    {
    public:
        void LoadBufferData(vector<float> &rBufferData, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        void LoadBufferData(GLvoid *bufferData, GLsizei elementSize, GLuint elementsCount, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        GLSL_BUFFER TargetBuffer() const;
        GLSL_GET BufferBindingParameter() const;
        
        static void UnbindCurrentBuffer();
    };
}
