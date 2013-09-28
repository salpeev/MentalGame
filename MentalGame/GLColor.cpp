//
//  GLColor.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLColor.h"




namespace GLRenderer
{
    GLColor::GLColor(): GLColor(0, 0, 0, 0)
    {
        
    }
    
    GLColor::GLColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a): r(r), g(g), b(b), a(a)
    {
        
    }
}