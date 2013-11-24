//
//  GLSLIndexBuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLIndexBuffer.h"
#include "GLLogger.h"
#include "GLDataConverter.h"



namespace GLRenderer
{
    GLSL_BUFFER GLSLIndexBuffer::TargetBuffer() const
    {
        return GLSL_ELEMENT_ARRAY_BUFFER;
    }
}