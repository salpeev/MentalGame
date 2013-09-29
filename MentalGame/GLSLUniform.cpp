//
//  GLSLUniform.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLUniform.h"



namespace GLRenderer
{
    GLSLUniform::GLSLUniform(GLchar *name, GLenum type, GLint size, GLint location): GLSLShaderValue(name, type, size, location)
    {
        
    }
}