//
//  GLSLMatrix.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLVector.h"



namespace Renderer {
    
    class GLSLMatrix2 {
    public:
        
        const float * Pointer() const;
        
        GLSLVector2 x;
        GLSLVector2 y;
    };
    
    
    
    class GLSLMatrix3 {
    public:
        const float * Pointer() const;
        
        GLSLVector3 x;
        GLSLVector3 y;
        GLSLVector3 z;
    };
    
    
    
    class GLSLMatrix4 {
    public:
        GLSLMatrix4();
        
        GLSLMatrix4 operator * (const GLSLMatrix4 &rMatrix) const;
        
        GLSLMatrix4 & Translate(float xTranslation, float yTranslation, float zTranslation);
        GLSLMatrix4 & RotateX(float radians);
        GLSLMatrix4 & RotateY(float radians);
        GLSLMatrix4 & RotateZ(float radians);
        
        const float * Pointer() const;
        
        // TODO: There is another way to create frustum
        static GLSLMatrix4 Frustum(float left, float right, float bottom, float top, float near, float far);
        static GLSLMatrix4 Translation(float xTranslation, float yTranslation, float zTranslation);
        static GLSLMatrix4 RotationX(float radians);
        static GLSLMatrix4 RotationY(float radians);
        static GLSLMatrix4 RotationZ(float radians);
        
        GLSLVector4 x;
        GLSLVector4 y;
        GLSLVector4 z;
        GLSLVector4 w;
    };
}
