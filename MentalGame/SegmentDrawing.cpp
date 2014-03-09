//
//  LineDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 21.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "SegmentDrawing.h"
#include "GLSLProgramContainer.h"
#include "PositionColorInitializer.h"
#include "ProjectionModelviewInitializer.h"
#include "GLSLVertex.h"
#include "VertexBuffer.h"



namespace Renderer {
    
    SegmentDrawing::SegmentDrawing (): m_start(Point()), m_end(Point()) {
        Point point0(-2.0, 0.0, 0.0);
        Point point1(2.0, 0.0, 0.0);
        
        vector<GLSLVertex1P1C> vertices;
        vertices.push_back(GLSLVertex1P1C(point0, GLColor(0.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point1, GLColor(1.0, 0.0, 0.0)));
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(GLSLVertex1P1C), vertices.size());
        
        m_attributeInitializer = new PositionColorInitializer();
        m_uniformInitializer = new ProjectionModelviewInitializer();
        
        Matrix4 modelview;
        modelview.Translate(0.0, 0.0, -4.5).RotateZ(0.1).RotateY(0.2);
        m_uniformInitializer->SetModelviewMatrix(modelview);
        
        m_drawRequest = new VertexBufferRequest(m_vertexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(GLSL_RENDER_MODE_LINES);
    }
    
    SegmentDrawing::~SegmentDrawing() {
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_vertexBuffer;
        delete m_drawRequest;
    }
    
#pragma mark - Public Methods
    
    void SegmentDrawing::SetStartPoint(const Point &rStart) {
        m_start = rStart;
    }
    
    void SegmentDrawing::SetEndPoint(const Point &rEnd) {
        m_end = rEnd;
    }
    
    Point SegmentDrawing::GetStartPoint() const {
        return m_start;
    }
    
    Point SegmentDrawing::GetEndPoint() const {
        return m_end;
    }
    
#pragma mark - Private Methods
    
    void SegmentDrawing::Update(float interval) {
        
    }
    
    void SegmentDrawing::Draw() const {
        Program *pProgram = GLSLProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}