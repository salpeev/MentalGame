//
//  TextureDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TextureDrawing.h"
#include "ProgramContainer.h"
#include "Point.h"
#include "Vertex.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "TexturePositionInitializer.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    TextureDrawing::TextureDrawing() {
        Point3 point0(-1.0, -1.0);
        Point3 point1(1.0, -1.0);
        Point3 point2(1.0, 1.0);
        Point3 point3(-1.0, 1.0);
        
        Point2 textureCoordinate0(0.0, 1.0);
        Point2 textureCoordinate1(1.0, 1.0);
        Point2 textureCoordinate2(1.0, 0.0);
        Point2 textureCoordinate3(0.0, 0.0);
        
        vector<Vertex1P1T> vertices;
        vertices.push_back(Vertex1P1T(point0, textureCoordinate0));
        vertices.push_back(Vertex1P1T(point1, textureCoordinate1));
        vertices.push_back(Vertex1P1T(point2, textureCoordinate2));
        vertices.push_back(Vertex1P1T(point3, textureCoordinate3));
        
        vector<GLushort> indices;
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(3);
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(Vertex1P1T), vertices.size());
        
        m_indexBuffer = new IndexBuffer();
        m_indexBuffer->LoadBufferData(indices);
        
        m_attributeInitializer = new TexturePositionInitializer();
        
        m_drawRequest = new VertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetRenderMode(RENDER_MODE_TRIANGLES);
        
        TextureImage *pTextureImage = ResourceManager::SharedInstance().LoadTexturePOT("Ukraine.jpg");
        m_texture = new Texture2D();
        m_texture->SetTextureImage(pTextureImage, 0);
        m_texture->GenerateMipMap(MIPMAP_HINT_FASTEST);
        
        delete pTextureImage;
    }
    
    TextureDrawing::~TextureDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_attributeInitializer;
        delete m_texture;
        delete m_drawRequest;
    }
    
#pragma mark - Protected Methods
    void TextureDrawing::Update(float interval) {
        
    }
    
    void TextureDrawing::Draw() const {
        m_texture->Bind();
        
        Program *pProgram = ProgramContainer::SharedInstance().GetTextureProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}