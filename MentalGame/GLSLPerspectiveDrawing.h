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
        void SetModelviewMatrix(GLSLMatrix4 &rModelviewMatrix);
        GLSLMatrix4 GetModelviewMatrix() const;
        
        void SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix);
        GLSLMatrix4 GetProjectionMatrix() const;
        
    private:
        string VertexShaderSource() const;
        string FragmentShaderSource() const;
        void InitializeAttributes(const map<string, GLSLAttribute *> *pAttributes, GLvoid *pData = NULL) const;
        void InitializeUniforms(const map<string, GLSLUniform *> *pUniforms) const;
        
        GLSLMatrix4 m_modelviewMatrix;
        GLSLMatrix4 m_projectionMatrix;
    };
}
