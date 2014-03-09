//
//  IndexBuffer.h
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
    
    class IndexBuffer : public Buffer {
    public:
        void LoadBufferData(const vector<GLushort> &rBufferData, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        void LoadBufferData(const vector<GLubyte> &rBufferData, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        GLSL_DATA_TYPE GetDataType() const;
        
        GLSL_BUFFER TargetBuffer() const;
        GET_PARAMETER BufferBindingParameter() const;
        
        static void UnbindCurrentBuffer();
        
    private:
        GLSL_DATA_TYPE m_dataType;
    };
}

