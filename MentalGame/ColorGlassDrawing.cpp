//
//  PlainDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorGlassDrawing.h"
#include "GLSLVertex.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLSLPositionColorInitializer.h"
#include "GLSLProjectionModelviewInitializer.h"
#include "GLSLProgramContainer.h"



namespace Renderer {
    
    ColorGlassDrawing::ColorGlassDrawing() {
        
        glEnable(GL_CULL_FACE);
        
        vector<GLSLVertex1P1C> vertices;
        vertices.push_back(GLSLVertex1P1C(GLPoint(-0.5, -0.5, 0.25), GLColor(1.0, 0.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(GLPoint(0.5, -0.5, 0.25), GLColor(0.0, 1.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(GLPoint(0.5, 0.5, 0.25), GLColor(0.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(GLPoint(-0.5, 0.5, 0.25), GLColor(1.0, 1.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(GLPoint(-0.5, -0.5, -0.25), GLColor(1.0, 1.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(GLPoint(0.5, -0.5, -0.25), GLColor(1.0, 1.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(GLPoint(0.5, 0.5, -0.25), GLColor(1.0, 1.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(GLPoint(-0.5, 0.5, -0.25), GLColor(1.0, 1.0, 1.0)));
        
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
        m_uniformInitializer->GetModelviewMatrix().Translate(0.0, 0.0, -5.0).RotateY(M_PI_4);
        
        m_drawRequest = new GLSLVertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(GLSL_RENDER_MODE_TRIANGLES);
    }
    
    ColorGlassDrawing::~ColorGlassDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
    }
    
    void ColorGlassDrawing::Draw() const {
        Program *pProgram = GLSLProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}
