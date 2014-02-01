//
//  Size.h
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace Renderer {
    
    class Size {
    public:
        Size();
        Size(GLfloat width, GLfloat height);
        
        GLfloat width;
        GLfloat height;
    };
}
