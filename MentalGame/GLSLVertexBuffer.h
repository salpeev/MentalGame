//
//  GLSLVertexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLBuffer.h"



namespace GLRenderer
{
    class GLSLVertexBuffer : public GLSLBuffer
    {
    public:
        GLSL_BUFFER TargetBuffer() const;
    };
}
