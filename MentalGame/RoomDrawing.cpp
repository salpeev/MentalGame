//
//  RoomDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RoomDrawing.h"
#include "Vertex.h"
#include "RenderingEngine.h"
#include "ProgramContainer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "PositionColorInitializer.h"
#include "ProjectionModelviewInitializer.h"
#include "PositionModelviewModifier.h"
#include "QuaternionModelviewModifier.h"



namespace Renderer {
    
    RoomDrawing::RoomDrawing() {
        // Rendering
        vector<Vertex1P1C> vertices;
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, -9.0), Color(0.0, 0.8, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, -9.0), Color(0.0, 0.8, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, -9.0), Color(0.0, 0.8, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, -9.0), Color(0.0, 0.6, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, -9.0), Color(0.0, 0.6, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, -9.0), Color(0.0, 0.6, 0.0)));
        
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, 1.0), Color(0.6, 0.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, 1.0), Color(0.6, 0.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, -9.0), Color(0.6, 0.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, 1.0), Color(0.4, 0.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, -9.0), Color(0.4, 0.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, -9.0), Color(0.4, 0.0, 0.0)));
        
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, -9.0), Color(0.0, 0.0, 1.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, 1.0), Color(0.0, 0.0, 1.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, 1.0), Color(0.0, 0.0, 1.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, -9.0), Color(0.0, 0.0, 0.8)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, 1.0), Color(0.0, 0.0, 0.8)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, -9.0), Color(0.0, 0.0, 0.8)));
        
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, -9.0), Color(1.0, 1.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, -9.0), Color(1.0, 1.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, 1.0), Color(1.0, 1.0, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, -9.0), Color(0.8, 0.8, 0.0)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, 1.0), Color(0.8, 0.8, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, 1.0), Color(0.8, 0.8, 0.0)));
        
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, 1.0), Color(0.5, 0.25, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, -9.0), Color(0.5, 0.25, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, -9.0), Color(0.5, 0.25, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, 1.0), Color(0.4, 0.2, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, -9.0), Color(0.4, 0.2, 0.0)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, 1.0), Color(0.4, 0.2, 0.0)));
        
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, 1.0), Color(1.0, 0.0, 0.4)));
        vertices.push_back(Vertex1P1C(Point(-4.0, -4.0, 1.0), Color(1.0, 0.0, 0.4)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, 1.0), Color(1.0, 0.0, 0.4)));
        vertices.push_back(Vertex1P1C(Point(4.0, -4.0, 1.0), Color(0.8, 0.0, 0.2)));
        vertices.push_back(Vertex1P1C(Point(-4.0, 4.0, 1.0), Color(0.8, 0.0, 0.2)));
        vertices.push_back(Vertex1P1C(Point(4.0, 4.0, 1.0), Color(0.8, 0.0, 0.2)));
        
//        Quaternion quaternion = Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), M_PI);
        Quaternion quaternion;
        m_quaternionModifier = new QuaternionModelviewModifier();
        m_quaternionModifier->SetQuaternion(quaternion);
        SetModelviewModifier(m_quaternionModifier);
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(Vertex1P1C), vertices.size());
        
        m_attributeInitializer = new PositionColorInitializer();
        m_uniformInitializer = new ProjectionModelviewInitializer();
        
        m_drawRequest = new VertexBufferRequest(m_vertexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(RENDER_MODE_TRIANGLES);
    }
    
    RoomDrawing::~RoomDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_drawRequest;
        delete m_positionModifier;
        delete m_quaternionModifier;
    }
    
    void RoomDrawing::Update(float interval) {
        m_uniformInitializer->SetModelviewMatrix(m_quaternionModifier->GetModelviewMatrix());
    }
    
    void RoomDrawing::Draw() const {
        RenderingEngine::SharedInstance().Enable(SERVER_CAPABILITY_DEPTH_TEST);
        RenderingEngine::SharedInstance().Disable(SERVER_CAPABILITY_CULL_FACE);
        
        Program *pProgram = ProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}
