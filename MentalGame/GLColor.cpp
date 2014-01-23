//
//  GLColor.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLColor.h"




namespace Renderer
{
    GLColor::GLColor(): GLColor(0.0f, 0.0f, 0.0f, 0.0f)
    {
        
    }
    
    GLColor::GLColor(GLfloat r, GLfloat g, GLfloat b): GLColor(r, g, b, 1.0f)
    {
        
    }
    
    GLColor::GLColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a): r(r), g(g), b(b), a(a)
    {
        
    }
}