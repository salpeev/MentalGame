//
//  GLPoint.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>



namespace GLRenderer
{
    class GLPoint2
    {
    public:
        GLPoint2();
        GLPoint2(GLfloat x, GLfloat y);
        
        GLfloat x;
        GLfloat y;
    };
    
    
    
    class GLPoint3
    {
    public:
        GLPoint3();
        GLPoint3(GLfloat x, GLfloat y, GLfloat z);
        
        GLfloat x;
        GLfloat y;
        GLfloat z;
    };
}
