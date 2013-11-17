//
//  GLDataConverter.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLDataConverter.h"



namespace GLRenderer
{
    GLenum GLDataConverter::OpenGLESUsageFromBufferUsage(GLSL_BUFFER_USAGE usage)
    {
        switch (usage) {
            case GLSL_BUFFER_USAGE_NONE: return 0;
            case GLSL_BUFFER_USAGE_STREAM_DRAW: return GL_STREAM_DRAW;
            case GLSL_BUFFER_USAGE_STATIC_DRAW: return GL_STATIC_DRAW;
            case GLSL_BUFFER_USAGE_DYNAMIC_DRAW: return GL_DYNAMIC_DRAW;
        }
    }
    
    GLenum GLDataConverter::OpenGLESShaderFromShaderType(GLSL_SHADER_TYPE shaderType)
    {
        switch (shaderType) {
            case GLSL_SHADER_TYPE_NONE: return 0;
            case GLSL_SHADER_TYPE_VERTEX: return GL_VERTEX_SHADER;
            case GLSL_SHADER_TYPE_FRAGMENT: return GL_FRAGMENT_SHADER;
        }
    }
}