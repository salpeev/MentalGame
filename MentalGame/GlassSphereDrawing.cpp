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
#include "PositionNormalInitializer.h"
#include "CubeMapUniformInitializer.h"
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
    
    GlassSphereDrawing::GlassSphereDrawing(): m_cubeMapCamera(nullptr) {
        vector<float> vertices;
        vector<unsigned short> indices;
        
        SphereSurface sphere(40, 40, 1.0f);
        sphere.GenerateVertices(vertices, /*VERTEX_ATTRIBUTE_COLOR | */VERTEX_ATTRIBUTE_NORMAL);
        sphere.GenerateTriangleIndices(indices);
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(vertices);
        
        m_indexBuffer = new IndexBuffer();
        m_indexBuffer->LoadBufferData(indices);
        
        m_positionModifier = new PositionModelviewModifier();
        SetModelviewModifier(m_positionModifier);
        
        m_attributeInitializer = new PositionNormalInitializer();
        m_uniformInitializer = new CubeMapUniformInitializer();
        
        m_drawRequest = new VertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(RENDER_MODE_TRIANGLES);
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
        
        // TODO: Should be removed
        static bool cameraAdded = false;
        static float time = 0;
        time += interval;
        if (time > 3.0f && !cameraAdded) {
            cameraAdded = true;
            
            Projection projection(M_PI_2, 1.0f, 1.0f, 20.0f);
            m_cubeMapCamera = new CubeMapCamera(CSize(1024, 1024), projection, new Framebuffer(), new DepthRenderbufferCompontent16(), nullptr, PIXEL_FORMAT_RGBA, PIXEL_TYPE_UBYTE);
            RenderingEngine::SharedInstance().AddOffscreenCamera(m_cubeMapCamera);
            
            m_cubeMapCamera->GetTextureCubeMap()->SetMinFilter(TEX_MIN_FILTER_NEAREST);
            m_cubeMapCamera->GetTextureCubeMap()->SetMagFilter(TEX_MAG_FILTER_NEAREST);
            
            Point3 position = GetPositionModelviewModifier()->GetPosition();
            m_cubeMapCamera->SetPosition(position);
        }
    }
    
    void GlassSphereDrawing::Draw(const Matrix4 &rProjectionMatrix) const {
        m_uniformInitializer->SetProjectionMatrix(rProjectionMatrix);
        
        if (m_cubeMapCamera) {
//            m_cubeMapCamera->GetTextureCubeMap()->GenerateMipMap(MIPMAP_HINT_NICEST);
//            RenderingEngine::SharedInstance().RemoveOffscreenCamera(m_cubeMapCamera);
        }
        
        Program *program = ProgramContainer::SharedInstance().GetCubeMapProgram();
        program->ExecuteDrawRequest(m_drawRequest);
    }
}