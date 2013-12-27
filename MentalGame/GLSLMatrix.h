//
//  GLSLMatrix.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLVector.h"



namespace GLRenderer
{
    class GLSLMatrix3
    {
    public:
        const float * Pointer() const;
        
        GLSLVector3 x;
        GLSLVector3 y;
        GLSLVector3 z;
    };
    
    
    
    class GLSLMatrix4
    {
    public:
        GLSLMatrix4();
        
        GLSLMatrix4 operator * (const GLSLMatrix4 &rMatrix) const;
        
        const float * Pointer() const;
        
        static GLSLMatrix4 Frustum(float left, float right, float bottom, float top, float near, float far);
        
        GLSLVector4 x;
        GLSLVector4 y;
        GLSLVector4 z;
        GLSLVector4 w;
    };
}
