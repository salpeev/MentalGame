//
//  Point.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Point.h"



namespace Renderer
{
    Point::Point(): Point(0.0f, 0.0f, 0.0f)
    {
        
    }
    
    Point::Point(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z)
    {
        
    }
}