//
//  Color.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace Renderer {
    
    class Color {
    public:
        Color();
        Color(GLfloat r, GLfloat g, GLfloat b);
        Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        
        GLfloat r;
        GLfloat g;
        GLfloat b;
        GLfloat a;
    };
}
