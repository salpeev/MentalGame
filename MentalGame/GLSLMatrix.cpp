//
//  GLSLMatrix.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLMatrix.h"



namespace GLRenderer
{
#pragma mark - GLSLMatrix3T
    
#pragma mark - GLSLMatrix4T
    
    GLSLMatrix4::GLSLMatrix4()
    {
        x.x = 1.0; x.y = 0.0; x.z = 0.0; x.w = 0.0;
        y.x = 0.0; y.y = 1.0; y.z = 0.0; y.w = 0.0;
        z.x = 0.0; z.y = 0.0; z.z = 1.0; z.w = 0.0;
        w.x = 0.0; w.y = 0.0; w.z = 0.0; w.w = 1.0;
    }
    
    GLSLMatrix4 GLSLMatrix4::Frustum(float left, float right, float bottom, float top, float near, float far)
    {
        float a = 2 * near / (right - left);
        float b = 2 * near / (top - bottom);
        float c = (right + left) / (right - left);
        float d = (top + bottom) / (top - bottom);
        float e = -(far + near) / (far - near);
        float f = - 2 * far * near / (far - near);
        
        GLSLMatrix4 m;
        m.x.x = a;   m.x.y = 0.0; m.x.z = 0.0; m.x.w = 0.0;
        m.y.x = 0.0; m.y.y = b;   m.y.z = 0.0; m.y.w = 0.0;
        m.z.x = c;   m.z.y = d;   m.z.z = e;   m.z.w = -1.0;
        m.w.x = 0.0; m.w.y = 0.0; m.w.z = f;   m.w.w = 0.0;
        return m;
    }
    
}