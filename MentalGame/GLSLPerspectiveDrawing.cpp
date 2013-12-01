//
//  GLSLPerspectiveDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 30.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLPerspectiveDrawing.h"
#include "GLResourceManager.h"
#include "GLSLAttribute.h"
#include "GLLogger.h"
#include "GLSLVertex.h"



namespace GLRenderer
{
    string GLSLPerspectiveDrawing::VertexShaderSource() const
    {
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.vsh");
        return vertexShaderSource;
    }
    
    string GLSLPerspectiveDrawing::FragmentShaderSource() const
    {
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.fsh");
        return fragmentShaderSource;
    }
    
    void GLSLPerspectiveDrawing::InitializeAttributes(const map<string, GLRenderer::GLSLAttribute *> *pAttributes, GLvoid *pData) const
    {
        
    }
}