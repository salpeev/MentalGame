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
        
        // TODO: Probably should be enabled in another place. Here should be initialized only if enabled.
        positionAttribute->EnableArray();
        colorAttribute->EnableArray();
        
        GLint positionSize = 3;
        GLint colorSize = 4;
        
        GLvoid *pPosition = NULL;
        GLvoid *pColor = NULL;
        
        if (pData)
        {
            pPosition = pData;
            pColor = (GLfloat *)pData + positionSize;
        }
        else
        {
            pPosition = NULL;
            pColor = (GLvoid *)(sizeof(GLSLVertex1P1C::m_position));
        }
        
        // TODO: Can be optimized with two floats per attribute
        glVertexAttribPointer(positionAttribute->GetLocation(), positionSize, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), pPosition);
        CheckError();
        
        glVertexAttribPointer(colorAttribute->GetLocation(), colorSize, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), pColor);
        CheckError();
    }
}