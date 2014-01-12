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
    private:
        string VertexShaderSource() const;
        string FragmentShaderSource() const;
    };
}
