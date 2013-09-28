//
//  GLVector.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  CopyrighGLfloat (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>



namespace GLRenderer
{
    class GLVector2
    {
    public:
        GLVector2();
        GLVector2(GLfloat x, GLfloat y);
        
        GLfloat x;
        GLfloat y;
    };
    
    
    
    class GLVector3
    {
    public:
        GLVector3();
        GLVector3(GLfloat x, GLfloat y, GLfloat z);
        
        GLfloat x;
        GLfloat y;
        GLfloat z;
    };
    
    
    
    class GLVector4
    {
    public:
        GLVector4();
        GLVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
        
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat w;
    };
}
