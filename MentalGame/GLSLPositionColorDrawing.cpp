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

using namespace std;



static const GLsizei PositionSize = 3;
static const GLsizei ColorSize = 4;



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
    
    void GLSLPositionColorDrawing::InitializeAttributesWithCurrentBuffer() const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        positionAttribute->SetBufferPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), 0);
        colorAttribute->SetBufferPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), PositionSize);
    }
    
    void GLSLPositionColorDrawing::InitializeAttributesWithVertexArray(GLSLVertexArray *pVertexArray) const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        GLvoid *pPosition = pVertexArray->GetData();
        GLvoid *pColor = (GLfloat *)pPosition + PositionSize;
        
        GLsizei vertexSize = pVertexArray->GetVertexSize();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pColor);
    }
    
    void GLSLPositionColorDrawing::InitializeAttributesWithVertexArrays(vector<GLSLVertexArray *> *pVertexArrays) const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        GLSLVertexArray *pPositionArray = pVertexArrays->at(0);
        GLSLVertexArray *pColorArray = pVertexArrays->at(1);
        
        GLvoid *pPosition = pPositionArray->GetData();
        GLvoid *pColor = pColorArray->GetData();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, 0, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, 0, pColor);
    }
}