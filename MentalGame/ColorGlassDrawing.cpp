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
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "PositionColorInitializer.h"
#include "ProjectionModelviewInitializer.h"
#include "GLSLProgramContainer.h"
#include "Polyhedron.h"
#include "CollisionDetector.h"
#include "MoveToAnimation.h"
#include "RotateToQuaternionAnimation.h"



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
        vertices.push_back(GLSLVertex1P1C(point0, Color(1.0, 0.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point1, Color(0.0, 1.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point2, Color(0.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point3, Color(1.0, 1.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point4, Color(0.0, 1.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point5, Color(1.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point6, Color(0.4, 0.2, 0.9)));
        vertices.push_back(GLSLVertex1P1C(point7, Color(0.7, 0.2, 0.0)));
        
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
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(GLSLVertex1P1C), vertices.size());
        
        m_indexBuffer = new IndexBuffer();
        m_indexBuffer->LoadBufferData(indices);
        
        m_attributeInitializer = new PositionColorInitializer();
        m_uniformInitializer = new ProjectionModelviewInitializer();
        
        m_drawRequest = new VertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(GLSL_RENDER_MODE_TRIANGLES);
        
        // Collision
        vector<Plane> planes;
        planes.push_back(Plane(point0, point1, point2));
        planes.push_back(Plane(point1, point5, point6));
        planes.push_back(Plane(point5, point4, point7));
        planes.push_back(Plane(point4, point0, point3));
        planes.push_back(Plane(point1, point0, point4));
        planes.push_back(Plane(point3, point2, point6));
        m_shape = new Polyhedron(planes);
    }
    
    ColorGlassDrawing::~ColorGlassDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_shape;
    }
    
    void ColorGlassDrawing::Update(float interval) {
        Matrix4 rotationMatrix(m_quaternion.ToMatrix3());
        
        Matrix4 modelview(rotationMatrix);
        modelview.MakeTranslation(m_position.x, m_position.y, m_position.z);
        m_uniformInitializer->SetModelviewMatrix(modelview);
        
        Matrix4 result = m_uniformInitializer->GetModelviewMatrix();
        Polyhedron polyhedron = m_shape->Transformed(result, true);
        
        Point pA(-1.5, -1.5, -4);
        Point pB(1.5, 1.5, -5);
        
        float start;
        float end;
        bool intersects = CollisionDetector::IntersectSegmentPolyhedron(pA, pB, polyhedron, start, end);
        Log("INTERSECTION: %d     %f   %f", intersects, start, end);
        
        
        
        static bool added = false;
        static float duration = 0.0f;
        duration += interval;
        if (duration > 3.0f && !added) {
            added = true;
            
            MoveToAnimation *moveTo = new MoveToAnimation(Point(-2, -2, -9), 15, ANIMATION_CURVE_EASE_IN);
            AddAnimation(moveTo);
            
            Quaternion newQuaternion = Quaternion::CreateFromAxisAngle(Vector3(1, 1, 0), M_PI);
            RotateToQuaternionAnimation *rotateToQuaternion = new RotateToQuaternionAnimation(newQuaternion, 15, ANIMATION_CURVE_LINEAR);
            AddAnimation(rotateToQuaternion);
        }
    }
    
    void ColorGlassDrawing::Draw() const {
        Program *pProgram = GLSLProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
    
#pragma mark - AnimationDelegate
    
    Point ColorGlassDrawing::GetPosition() const {
        return m_position;
    }
    
    Quaternion ColorGlassDrawing::GetQuaternion() const {
        return m_quaternion;
    }
    
    void ColorGlassDrawing::SetPosition(const Point &rPosition) {
        m_position = rPosition;
    }
    
    void ColorGlassDrawing::SetQuaternion(const Quaternion &rQuaternion) {
        m_quaternion = rQuaternion;
    }
    
}
