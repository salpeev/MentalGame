//
//  GLVector.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLVector.h"



namespace Renderer
{
    GLVector2::GLVector2(): GLVector2(0.0f, 0.0f)
    {
        
    }
    
    GLVector2::GLVector2(GLfloat x, GLfloat y): x(x), y(y)
    {
        
    }
    
    
    
    GLVector3::GLVector3(): GLVector3(0.0f, 0.0f, 0.0f)
    {
        
    }
    
    GLVector3::GLVector3(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z)
    {
        
    }
    
    
    
    GLVector4::GLVector4(): GLVector4(0.0f, 0.0f, 0.0f, 0.0f)
    {
        
    }
    
    GLVector4::GLVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w): x(x), y(y), z(z), w(w)
    {
        
    }
}