//
//  LineDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 21.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TestDrawing.h"
#include "GLSLProgramContainer.h"
#include "GLSLPositionColorInitializer.h"
#include "GLSLProjectionModelviewInitializer.h"
#include "GLSLVertex.h"
#include "GLSLVertexBuffer.h"



namespace Renderer {
    
    TestDrawing::TestDrawing () {
        Point point0(-2.0, 0.0, 0.0);
        Point point1(2.0, 0.0, 0.0);
        
        vector<GLSLVertex1P1C> vertices;
        vertices.push_back(GLSLVertex1P1C(point0, GLColor(0.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point1, GLColor(1.0, 0.0, 0.0)));
        
        m_vertexBuffer = new GLSLVertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(GLSLVertex1P1C), vertices.size());
        
        m_attributeInitializer = new GLSLPositionColorInitializer();
        m_uniformInitializer = new GLSLProjectionModelviewInitializer();
        m_uniformInitializer->GetModelviewMatrix().Translate(0.0, 0.0, -4.5).RotateZ(0.1).RotateY(0.2);
        
        m_drawRequest = new GLSLVertexBufferRequest(m_vertexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(GLSL_RENDER_MODE_LINES);
    }
    
    TestDrawing::~TestDrawing() {
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_vertexBuffer;
        delete m_drawRequest;
    }
    
    void TestDrawing::Update(float interval) {
        
    }
    
    void TestDrawing::Draw() const {
        Program *pProgram = GLSLProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}