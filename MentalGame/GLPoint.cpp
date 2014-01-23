//
//  GLPoint.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLPoint.h"



namespace Renderer
{
    GLPoint::GLPoint(): GLPoint(0, 0, 0)
    {
        
    }
    
    GLPoint::GLPoint(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z)
    {
        
    }
}