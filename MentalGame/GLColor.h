//
//  GLColor.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace GLRenderer
{
    class GLColor
    {
    public:
        GLColor();
        GLColor(GLfloat r, GLfloat g, GLfloat b);
        GLColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        
        GLfloat r;
        GLfloat g;
        GLfloat b;
        GLfloat a;
    };
}
