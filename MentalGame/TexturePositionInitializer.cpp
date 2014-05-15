//
//  TexturePositionInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 04.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TexturePositionInitializer.h"
#include "Attribute.h"
#include "Vertex.h"
#include "VertexArray.h"
#include "Logger.h"



static const char *PositionAttributeName = "a_position";
static const char *TextureCoordAttributeName = "a_textureCoordinate";
static const GLsizei PositionSize = 3;
static const GLsizei TextureCoordSize = 2;



namespace Renderer {
    void TexturePositionInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *texCoordAttribute = pAttributes->at(TextureCoordAttributeName);
        
        GLsizei colorOffset = PositionSize * sizeof(GLfloat);
        
        positionAttribute->SetBufferPointer(PositionSize, DATA_TYPE_FLOAT, false, sizeof(Vertex1P1T), 0);
        texCoordAttribute->SetBufferPointer(TextureCoordSize, DATA_TYPE_FLOAT, false, sizeof(Vertex1P1T), colorOffset);
    }
    
    void TexturePositionInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes, VertexArray *pVertexArray) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *texCoordAttribute = pAttributes->at(TextureCoordAttributeName);
        
        GLvoid *pPosition = pVertexArray->GetData();
        GLvoid *pTexCoord = (GLfloat *)pPosition + PositionSize;
        
        GLsizei vertexSize = pVertexArray->GetVertexSize();
        
        positionAttribute->SetDataPointer(PositionSize, DATA_TYPE_FLOAT, false, vertexSize, pPosition);
        texCoordAttribute->SetDataPointer(TextureCoordSize, DATA_TYPE_FLOAT, false, vertexSize, pTexCoord);
    }
    
    void TexturePositionInitializer::InitializeAttributes(map<string, Attribute *> *pAttributes, vector<VertexArray *> *pVertexArrays) const {
        Attribute *positionAttribute = pAttributes->at(PositionAttributeName);
        Attribute *texCoordAttribute = pAttributes->at(TextureCoordAttributeName);
        
        VertexArray *pPositionArray = pVertexArrays->at(0);
        VertexArray *pColorArray = pVertexArrays->at(1);
        
        GLvoid *pPosition = pPositionArray->GetData();
        GLvoid *pTexCoord = pColorArray->GetData();
        
        positionAttribute->SetDataPointer(PositionSize, DATA_TYPE_FLOAT, false, 0, pPosition);
        texCoordAttribute->SetDataPointer(TextureCoordSize, DATA_TYPE_FLOAT, false, sizeof(Point3), pTexCoord);
    }
}