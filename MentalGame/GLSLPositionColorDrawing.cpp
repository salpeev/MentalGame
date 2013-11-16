//
//  GLSLPositionColorDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLPositionColorDrawing.h"



namespace GLRenderer
{
    GLSLPositionColorDrawing::GLSLPositionColorDrawing(): GLSLDrawing()
    {
        
    }
    
    GLSLPositionColorDrawing::~GLSLPositionColorDrawing()
    {
        
    }
    
    string GLSLPositionColorDrawing::VertexShaderName() const
    {
        return "PositionColorShader.vsh";
    }
    
    string GLSLPositionColorDrawing::FragmentShaderName() const
    {
        return "PositionColorShader.fsh";
    }
}