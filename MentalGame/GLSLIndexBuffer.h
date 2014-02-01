//
//  GLSLIndexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLBuffer.h"
#include <vector>

using namespace std;



namespace Renderer
{
    class GLSLIndexBuffer : public GLSLBuffer
    {
    public:
        void LoadBufferData(vector<GLushort> &rBufferData, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        void LoadBufferData(vector<GLubyte> &rBufferData, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        GLSL_DATA_TYPE GetDataType() const;
        
        GLSL_BUFFER TargetBuffer() const;
        GET_PARAMETER BufferBindingParameter() const;
        
        static void UnbindCurrentBuffer();
        
    private:
        GLSL_DATA_TYPE m_dataType;
    };
}

