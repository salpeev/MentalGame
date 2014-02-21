//
//  PlainDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorGlassDrawing.h"
#include "GLLogger.h"
#include "GLSLVertex.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLSLPositionColorInitializer.h"
#include "GLSLProjectionModelviewInitializer.h"
#include "GLSLProgramContainer.h"
#include "Polyhedron.h"
#include "CollisionDetector.h"



namespace Renderer {
    
    ColorGlassDrawing::ColorGlassDrawing() {
        
        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);
        
        Point point0(-1.0, -1.0, 0.25);
        Point point1(1.0, -1.0, 0.25);
        Point point2(1.0, 1.0, 0.25);
        Point point3(-1.0, 1.0, 0.25);
        Point point4(-1.0, -1.0, -0.25);
        Point point5(1.0, -1.0, -0.25);
        Point point6(1.0, 1.0, -0.25);
        Point point7(-1.0, 1.0, -0.25);
        
        // Rendering
        vector<GLSLVertex1P1C> vertices;
        vertices.push_back(GLSLVertex1P1C(point0, GLColor(1.0, 0.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point1, GLColor(0.0, 1.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point2, GLColor(0.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point3, GLColor(1.0, 1.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point4, GLColor(0.0, 1.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point5, GLColor(1.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point6, GLColor(0.4, 0.2, 0.9)));
        vertices.push_back(GLSLVertex1P1C(point7, GLColor(0.7, 0.2, 0.0)));
        
        vector<GLushort> indices;
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(3);
        indices.push_back(1);
        indices.push_back(5);
        indices.push_back(6);
        indices.push_back(1);
        indices.push_back(6);
        indices.push_back(2);
        indices.push_back(5);
        indices.push_back(4);
        indices.push_back(7);
        indices.push_back(5);
        indices.push_back(7);
        indices.push_back(6);
        indices.push_back(4);
        indices.push_back(0);
        indices.push_back(3);
        indices.push_back(4);
        indices.push_back(3);
        indices.push_back(7);
        indices.push_back(3);
        indices.push_back(2);
        indices.push_back(6);
        indices.push_back(3);
        indices.push_back(6);
        indices.push_back(7);
        indices.push_back(1);
        indices.push_back(0);
        indices.push_back(4);
        indices.push_back(1);
        indices.push_back(4);
        indices.push_back(5);
        
        m_vertexBuffer = new GLSLVertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(GLSLVertex1P1C), vertices.size());
        
        m_indexBuffer = new GLSLIndexBuffer();
        m_indexBuffer->LoadBufferData(indices);
        
        m_attributeInitializer = new GLSLPositionColorInitializer();
        m_uniformInitializer = new GLSLProjectionModelviewInitializer();
        m_uniformInitializer->GetModelviewMatrix().Translate(0.0, 0.0, -5.5).RotateY(M_PI_4);
        
        m_drawRequest = new GLSLVertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(GLSL_RENDER_MODE_TRIANGLES);
        
        // Collision
        m_planes = new vector<Plane>();
        m_planes->push_back(Plane(point0, point1, point2));
        m_planes->push_back(Plane(point1, point5, point6));
        m_planes->push_back(Plane(point5, point4, point7));
        m_planes->push_back(Plane(point4, point0, point3));
        m_planes->push_back(Plane(point1, point0, point4));
        m_planes->push_back(Plane(point3, point2, point6));
    }
    
    ColorGlassDrawing::~ColorGlassDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_planes;
    }
    
    void ColorGlassDrawing::Update(float interval) {
        m_uniformInitializer->GetModelviewMatrix().RotateX(interval).RotateY(interval).RotateZ(interval);
        
        Matrix4 result = m_uniformInitializer->GetModelviewMatrix()/* * m_uniformInitializer->GetProjectionMatrix()*/;
        Polyhedron polyhedron(*m_planes);
        polyhedron.Transform(result);
//        Plane plane = polyhedron.GetPlanes()[0];
        
        Point vA(0.2, 0.2, -0.0);
        Point vB(2.0, 2.0, -12.0);
//        Vector4 vTA = m_uniformInitializer->GetModelviewMatrix() * vA;
//        Vector4 vTB = m_uniformInitializer->GetModelviewMatrix() * vB;
        
        float start;
        float end;
        bool intersects = CollisionDetector::IntersectSegmentPolyhedron(vA, vB, polyhedron, start, end);
        Log("AAA: %d     %f   %f", intersects, start, end);
    }
    
    void ColorGlassDrawing::Draw() const {
        Program *pProgram = GLSLProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}
