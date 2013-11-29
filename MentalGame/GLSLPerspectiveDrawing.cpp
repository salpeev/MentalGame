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
    
    void GLSLPerspectiveDrawing::InitializeAttributes(const map<string, GLRenderer::GLSLAttribute *> *pAttributes) const
    {
        GLSLAttribute *positionAttribute = pAttributes->at("a_position");
        GLSLAttribute *colorAttribute = pAttributes->at("a_color");
        
        positionAttribute->EnableArray();
        colorAttribute->EnableArray();
        
        // TODO: Can be optimized with two floats per attribute
        glVertexAttribPointer(positionAttribute->GetLocation(), 3, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), NULL);
        CheckError();
        
        glVertexAttribPointer(colorAttribute->GetLocation(), 4, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), (GLvoid *)(sizeof(GLSLVertex1P1C::m_position)));
        CheckError();
    }
}