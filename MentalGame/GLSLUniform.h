//
//  GLSLUniform.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLShaderValue.h"



namespace GLRenderer
{
    class GLSLUniform: public GLSLShaderValue
    {
    public:
        GLSLUniform(GLchar *name, GLenum type, GLint size, GLint location);
    };
}
