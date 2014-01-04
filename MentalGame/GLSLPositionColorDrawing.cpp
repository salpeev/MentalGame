//
//  GLSLPositionColorDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLPositionColorDrawing.h"
#include "GLLogger.h"
#include "GLResourceManager.h"
#include "GLSLAttribute.h"
#include "GLSLVertex.h"


// Test
#include <iostream>
#include <vector>

using namespace std;



namespace GLRenderer
{
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
    
    void GLSLPositionColorDrawing::InitializeAttributes(GLvoid *pData) const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        GLint positionSize = 3;
        GLint colorSize = 4;
        
        if (pData)
        {
            GLvoid *pPosition = pData;
            GLvoid *pColor = (GLfloat *)pData + positionSize;
            
            positionAttribute->SetDataPointer(positionSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), pPosition);
            colorAttribute->SetDataPointer(colorSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), pColor);
        }
        else
        {
            positionAttribute->SetBufferPointer(positionSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), 0);
            colorAttribute->SetBufferPointer(colorSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), sizeof(GLSLVertex1P1C::m_position));
        }
    }
}