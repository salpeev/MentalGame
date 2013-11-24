//
//  GLSLIndexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLBuffer.h"



namespace GLRenderer
{
    class GLSLIndexBuffer : public GLSLBuffer
    {
    public:
        GLSL_BUFFER TargetBuffer() const;
        GLSL_GET_PARAMETER BufferBindingParameter() const;
        
        static void UnbindCurrentBuffer();
    };
}

