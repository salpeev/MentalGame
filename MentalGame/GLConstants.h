//
//  GLConstants.h
//  MentalGame
//
//  Created by Sergey Alpeev on 05.10.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once



enum GLSL_BUFFER_USAGE
{
    GLSL_BUFFER_USAGE_NONE,
    GLSL_BUFFER_USAGE_STREAM_DRAW,
    GLSL_BUFFER_USAGE_STATIC_DRAW,
    GLSL_BUFFER_USAGE_DYNAMIC_DRAW
};

enum GLSL_SHADER_TYPE
{
    GLSL_SHADER_TYPE_NONE,
    GLSL_SHADER_TYPE_VERTEX,
    GLSL_SHADER_TYPE_FRAGMENT
};