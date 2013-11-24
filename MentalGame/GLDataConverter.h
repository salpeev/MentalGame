//
//  GLDataConverter.h
//  MentalGame
//
//  Created by Sergey Alpeev on 16.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include "GLConstants.h"



namespace GLRenderer
{
    class GLDataConverter
    {
    public:
        static GLenum OpenGLESBufferFromBuffer(GLSL_BUFFER buffer);
        static GLenum OpenGLESUsageFromBufferUsage(GLSL_BUFFER_USAGE usage);
        static GLenum OpenGLESShaderFromShaderType(GLSL_SHADER_TYPE shaderType);
    };
}
