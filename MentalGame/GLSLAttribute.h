//
//  GLSLAttribute.h
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLShaderValue.h"

using namespace std;



namespace GLRenderer
{
    class GLSLAttribute: public GLSLShaderValue
    {
    public:
        GLSLAttribute(GLchar *name, GLenum type, GLint size, GLint location);
    };
}
