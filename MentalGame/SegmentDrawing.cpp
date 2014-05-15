//
//  LineDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 21.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "SegmentDrawing.h"
#include "ProgramContainer.h"
#include "PositionColorInitializer.h"
#include "ProjectionModelviewInitializer.h"
#include "Vertex.h"
#include "VertexBuffer.h"



namespace Renderer {
    
    SegmentDrawing::SegmentDrawing (): m_start(Point3()), m_end(Point3()), m_startColor(Color(1.0, 1.0, 1.0)), m_endColor(Color(1.0, 1.0, 1.0)) {
        vector<Vertex1P1C> vertices;
        vertices.push_back(Vertex1P1C(m_start, m_startColor));
        vertices.push_back(Vertex1P1C(m_end, m_endColor));
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(Vertex1P1C), vertices.size(), GLSL_BUFFER_USAGE_DYNAMIC_DRAW);
        
        m_attributeInitializer = new PositionColorInitializer();
        m_uniformInitializer = new ProjectionModelviewInitializer();
        
        m_drawRequest = new VertexBufferRequest(m_vertexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(RENDER_MODE_LINES);
    }
    
    SegmentDrawing::~SegmentDrawing() {
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_vertexBuffer;
        delete m_drawRequest;
    }
    
#pragma mark - Public Methods
    
    void SegmentDrawing::SetStartPoint(const Point3 &rStart) {
        m_start = rStart;
        
        m_vertexBuffer->LoadBufferSubData(&m_start, 0, sizeof(Point3));
    }
    
    void SegmentDrawing::SetEndPoint(const Point3 &rEnd) {
        m_end = rEnd;
        
        GLintptr offset = sizeof(Point3) + sizeof(Color);
        m_vertexBuffer->LoadBufferSubData(&m_end, offset, sizeof(Point3));
    }
    
    void SegmentDrawing::SetStartColor(const Color &rStartColor) {
        m_startColor = rStartColor;
        
        GLintptr offset = sizeof(Point3);
        m_vertexBuffer->LoadBufferSubData(&m_startColor, offset, sizeof(Color));
    }
    
    void SegmentDrawing::SetEndColor(const Color &rEndColor) {
        m_endColor = rEndColor;
        
        GLintptr offset = sizeof(Point3) + sizeof(Color) + sizeof(Point3);
        m_vertexBuffer->LoadBufferSubData(&m_endColor, offset, sizeof(Color));
    }
    
    Point3 SegmentDrawing::GetStartPoint() const {
        return m_start;
    }
    
    Point3 SegmentDrawing::GetEndPoint() const {
        return m_end;
    }
    
    Color SegmentDrawing::GetStartColor() const {
        return m_startColor;
    }
    
    Color SegmentDrawing::GetEndColor() const {
        return m_endColor;
    }
    
#pragma mark - Private Methods
    
    void SegmentDrawing::Update(float interval) {
        
    }
    
    void SegmentDrawing::Draw() const {
        Program *pProgram = ProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}