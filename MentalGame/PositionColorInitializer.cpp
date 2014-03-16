//
//  PositionColorInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "PositionColorInitializer.h"
#include "Attribute.h"
#include "GLSLVertex.h"
#include "VertexArray.h"



static const char *PositionAttributeName = "a_position";
static const char *ColorAttributeName = "a_color";
static const GLsizei PositionSize = 3;
static const GLsizei ColorSize = 4;



namespace Renderer {
    void PositionColorInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *colorAttribute = pAttributes->at(ColorAttributeName);
        
        GLsizei colorOffset = PositionSize * sizeof(GLfloat);
        
        positionAttribute->SetBufferPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), 0);
        colorAttribute->SetBufferPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), colorOffset);
    }
    
    void PositionColorInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes, VertexArray *pVertexArray) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *colorAttribute = pAttributes->at(ColorAttributeName);
        
        GLvoid *pPosition = pVertexArray->GetData();
        GLvoid *pColor = (GLfloat *)pPosition + PositionSize;
        
        GLsizei vertexSize = pVertexArray->GetVertexSize();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pColor);
    }
    
    void PositionColorInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes, vector<VertexArray *> *pVertexArrays) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *colorAttribute = pAttributes->at(ColorAttributeName);
        
        VertexArray *pPositionArray = pVertexArrays->at(0);
        VertexArray *pColorArray = pVertexArrays->at(1);
        
        GLvoid *pPosition = pPositionArray->GetData();
        GLvoid *pColor = pColorArray->GetData();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLfloat) * 3, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, 0, pColor);
    }
}