//
//  GLSLPerspectiveDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 30.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLDrawing.h"
#include "GLSLQuaternion.h"



namespace GLRenderer
{
    class GLSLPerspectiveDrawing: public GLSLDrawing
    {
        void SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix) const;
        GLSLMatrix4 GetProjectionMatrix() const;
        
        void SetModelviewMatrix(GLSLMatrix4 &rModelviewMatrix) const;
        GLSLMatrix4 GetModelviewMatrix() const;
        
    private:
        string VertexShaderSource() const;
        string FragmentShaderSource() const;
        void InitializeAttributes(GLvoid *pData = NULL) const;
        void InitializeUniforms() const;
    };
}
