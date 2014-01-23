//
//  GLSLPositionColorInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLPositionColorInitializer.h"
#include "GLSLAttribute.h"
#include "GLSLVertex.h"
#include "GLSLVertexArray.h"



static const char *PositionAttributeName = "a_position";
static const char *ColorAttributeName = "a_color";
static const GLsizei PositionSize = 3;
static const GLsizei ColorSize = 4;



namespace Renderer
{
    void GLSLPositionColorInitializer::InitializeAttributes(map<string, GLSLAttribute *> *pAttributes) const
    {
        GLSLAttribute *positionAttribute = pAttributes->at(PositionAttributeName);
        GLSLAttribute *colorAttribute = pAttributes->at(ColorAttributeName);
        
        GLsizei colorOffset = PositionSize * sizeof(GLfloat);
        
        positionAttribute->SetBufferPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), 0);
        colorAttribute->SetBufferPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), colorOffset);
    }
    
    void GLSLPositionColorInitializer::InitializeAttributes(map<string, GLSLAttribute *> *pAttributes, GLSLVertexArray *pVertexArray) const
    {
        GLSLAttribute *positionAttribute = pAttributes->at(PositionAttributeName);
        GLSLAttribute *colorAttribute = pAttributes->at(ColorAttributeName);
        
        GLvoid *pPosition = pVertexArray->GetData();
        GLvoid *pColor = (GLfloat *)pPosition + PositionSize;
        
        GLsizei vertexSize = pVertexArray->GetVertexSize();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pColor);
    }
    
    void GLSLPositionColorInitializer::InitializeAttributes(map<string, GLSLAttribute *> *pAttributes, vector<GLSLVertexArray *> *pVertexArrays) const
    {
        GLSLAttribute *positionAttribute = pAttributes->at(PositionAttributeName);
        GLSLAttribute *colorAttribute = pAttributes->at(ColorAttributeName);
        
        GLSLVertexArray *pPositionArray = pVertexArrays->at(0);
        GLSLVertexArray *pColorArray = pVertexArrays->at(1);
        
        GLvoid *pPosition = pPositionArray->GetData();
        GLvoid *pColor = pColorArray->GetData();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, 0, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, 0, pColor);
    }
}