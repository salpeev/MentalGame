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
    class Vector3;
    
    
    
    class Point
    {
    public:
        Point();
        
        Point(GLfloat x, GLfloat y);
        Point(GLfloat x, GLfloat y, GLfloat z);
        
        Vector3 operator-(const Point &rPoint) const;
        operator Vector3() const;
        
        GLfloat x;
        GLfloat y;
        GLfloat z;
    };
}
