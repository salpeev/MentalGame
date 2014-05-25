//
//  GlassSphereDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GlassSphereDrawing.h"
#include "SphereSurface.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "PositionModelviewModifier.h"
#include "PositionColorInitializer.h"
#include "ProjectionModelviewInitializer.h"
#include "ProgramContainer.h"
#include "DrawRequest.h"
#include "CubeMapCamera.h"
#include "RenderingEngine.h"
#include "DepthRenderbufferComponent16.h"
#include "TextureCubeMap.h"
#include "ResourceManager.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    GlassSphereDrawing::GlassSphereDrawing() {
        vector<float> vertices;
        vector<unsigned short> indices;
        
        SphereSurface sphere(20, 20, 1.0f);
        sphere.GenerateVertices(vertices, VERTEX_ATTRIBUTE_COLOR/* | VERTEX_ATTRIBUTE_NORMAL*/);
        sphere.GenerateLineIndices(indices);
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(vertices);
        
        m_indexBuffer = new IndexBuffer();
        m_indexBuffer->LoadBufferData(indices);
        
        m_positionModifier = new PositionModelviewModifier();
        SetModelviewModifier(m_positionModifier);
        
        m_attributeInitializer = new PositionColorInitializer();
        m_uniformInitializer = new ProjectionModelviewInitializer();
        
        m_drawRequest = new VertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(RENDER_MODE_LINES);
        
        
        
        
        // TODO: Doesn't work!!!
        Projection projection(M_PI_2, 1.0f, 1.0f, 20.0f);
        m_cubeMapCamera = new CubeMapCamera(CSize(128, 128), projection, new Framebuffer(), new DepthRenderbufferCompontent16(), nullptr, PIXEL_FORMAT_RGBA, PIXEL_TYPE_USHORT_5_5_5_1);
//        RenderingEngine::SharedInstance().AddOffscreenCamera(m_cubeMapCamera);
    }
    
    GlassSphereDrawing::~GlassSphereDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_positionModifier;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_drawRequest;
        delete m_positionModifier;
        delete m_cubeMapCamera;
    }
    
    PositionModelviewModifier * GlassSphereDrawing::GetPositionModelviewModifier() const {
        return m_positionModifier;
    }
    
    void GlassSphereDrawing::Update(float interval) {
        m_uniformInitializer->SetModelviewMatrix(GetModelviewMatrix());
        
        Point3 position = GetPositionModelviewModifier()->GetPosition();
        m_cubeMapCamera->SetPosition(position);
    }
    
    void GlassSphereDrawing::Draw() const {
        Program *program = ProgramContainer::SharedInstance().GetPerspectiveProgram();
        program->ExecuteDrawRequest(m_drawRequest);
    }
}