//
//  GLSLPositionColorDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLPositionColorDrawing.h"
#include "GLResourceManager.h"



namespace GLRenderer
{
    GLSLPositionColorDrawing::GLSLPositionColorDrawing(): GLSLDrawing()
    {
        
    }
    
    GLSLPositionColorDrawing::~GLSLPositionColorDrawing()
    {
        
    }
    
    string GLSLPositionColorDrawing::VertexShaderSource() const
    {
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.vsh");
        return vertexShaderSource;
    }
    
    string GLSLPositionColorDrawing::FragmentShaderSource() const
    {
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.fsh");
        return fragmentShaderSource;
    }
}