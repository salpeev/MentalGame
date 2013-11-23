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
    
    void GLSLPositionColorDrawing::InitializeAttributes(const map<string, GLRenderer::GLSLAttribute *> *pAttributes) const
    {
        GLSLAttribute *positionAttribute = pAttributes->at("a_position");
        GLSLAttribute *colorAttribute = pAttributes->at("a_color");
        
        positionAttribute->EnableArray();
        colorAttribute->EnableArray();
        
        glVertexAttribPointer(positionAttribute->GetLocation(), 3, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), NULL);
        CheckError();
        
        glVertexAttribPointer(colorAttribute->GetLocation(), 4, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), (GLvoid *)(sizeof(GLSLVertex1P1C::m_position)));
        CheckError();
    }
}