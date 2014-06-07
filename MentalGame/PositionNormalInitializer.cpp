//
//  PositionNormalInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.06.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "PositionNormalInitializer.h"
#include "Attribute.h"
#include "Vertex.h"
#include "VertexArray.h"
#include <map>

using namespace std;



static const char *PositionAttributeName = "a_position";
static const char *NormalAttributeName = "a_normal";
static const GLsizei PositionSize = 3;
static const GLsizei NormalSize = 2;



namespace Renderer {
    void PositionNormalInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *normalAttribute = pAttributes->at(NormalAttributeName);
        
        GLsizei colorOffset = PositionSize * sizeof(GLfloat);
        
        positionAttribute->SetBufferPointer(PositionSize, DATA_TYPE_FLOAT, false, sizeof(Vertex1P1T), 0);
        normalAttribute->SetBufferPointer(NormalSize, DATA_TYPE_FLOAT, false, sizeof(Vertex1P1T), colorOffset);
    }
    
    void PositionNormalInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes, VertexArray *pVertexArray) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *normalAttribute = pAttributes->at(NormalAttributeName);
        
        GLvoid *pPosition = pVertexArray->GetData();
        GLvoid *pTexCoord = (GLfloat *)pPosition + PositionSize;
        
        GLsizei vertexSize = pVertexArray->GetVertexSize();
        
        positionAttribute->SetDataPointer(PositionSize, DATA_TYPE_FLOAT, false, vertexSize, pPosition);
        normalAttribute->SetDataPointer(NormalSize, DATA_TYPE_FLOAT, false, vertexSize, pTexCoord);
    }
    
    void PositionNormalInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes, vector<VertexArray *> *pVertexArrays) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *normalAttribute = pAttributes->at(NormalAttributeName);
        
        VertexArray *pPositionArray = pVertexArrays->at(0);
        VertexArray *pColorArray = pVertexArrays->at(1);
        
        GLvoid *pPosition = pPositionArray->GetData();
        GLvoid *pTexCoord = pColorArray->GetData();
        
        positionAttribute->SetDataPointer(PositionSize, DATA_TYPE_FLOAT, false, 0, pPosition);
        normalAttribute->SetDataPointer(NormalSize, DATA_TYPE_FLOAT, false, sizeof(Point3), pTexCoord);
    }
}