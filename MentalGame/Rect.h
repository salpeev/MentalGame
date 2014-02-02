//
//  Rect.h
//  MentalGame
//
//  Created by Sergey Alpeev on 02.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace Renderer {
    
    class Rect {
    public:
        Rect();
        Rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
        
        GLfloat x;
        GLfloat y;
        GLfloat width;
        GLfloat height;
    };
}
