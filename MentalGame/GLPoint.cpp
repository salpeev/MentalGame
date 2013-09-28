//
//  GLPoint.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLPoint.h"



namespace GLRenderer
{
    GLPoint2::GLPoint2(): GLPoint2(0, 0)
    {
        
    }
    
    GLPoint2::GLPoint2(GLfloat x, GLfloat y): x(x), y(y)
    {
        
    }
    
    
    
    GLPoint3::GLPoint3(): GLPoint3(0, 0, 0)
    {
        
    }
    
    GLPoint3::GLPoint3(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z)
    {
        
    }
}