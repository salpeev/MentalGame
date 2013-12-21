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
    GLenum GLDataConverter::OpenGLESBufferFromBuffer(GLSL_BUFFER buffer)
    {
        switch (buffer) {
            case GLSL_ARRAY_BUFFER: return GL_ARRAY_BUFFER;
            case GLSL_ELEMENT_ARRAY_BUFFER: return GL_ELEMENT_ARRAY_BUFFER;
        }
    }
    
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
    
    GLenum GLDataConverter::OpenGLESGetParameterFromGetParameter(GLSL_GET_PARAMETER getParameter)
    {
        switch (getParameter) {
            case GLSL_GET_PARAMETER_ARRAY_BUFFER_BINDING: return GL_ARRAY_BUFFER_BINDING;
            case GLSL_GET_PARAMETER_ELEMENT_ARRAY_BUFFER_BINDING: return GL_ELEMENT_ARRAY_BUFFER_BINDING;
        }
    }
    
    GLenum GLDataConverter::OpenGLESDataTypeFromDataType(GLSL_DATA_TYPE dataType)
    {
        switch (dataType) {
            case GLSL_DATA_TYPE_UNSIGNED_BYTE: return GL_UNSIGNED_BYTE;
            case GLSL_DATA_TYPE_UNSIGNED_SHORT: return GL_UNSIGNED_SHORT;
        }
    }
}