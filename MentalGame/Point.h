//
//  Point.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace Renderer
{
    class Point
    {
    public:
        Point();
        Point(GLfloat x, GLfloat y, GLfloat z);
        
        GLfloat x;
        GLfloat y;
        GLfloat z;
    };
}
