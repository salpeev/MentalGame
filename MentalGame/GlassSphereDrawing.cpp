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
    
    GlassSphereDrawing::GlassSphereDrawing(): m_cubeMapCamera(nullptr), m_drawingMode(GlassSphereDrawingMode::GlassSphereDrawingModeDefault) {
        vector<float> vertices;
        vector<unsigned short> indices;
        
        SphereSurface sphere(30, 30, 1.0f);
        sphere.GenerateVertices(vertices, VERTEX_ATTRIBUTE_NORMAL);
        sphere.GenerateTriangleIndices(indices);
        
        m_vertexBuffer = new VertexBuffer();
        m_vertexBuffer->LoadBufferData(vertices);
        
        m_indexBuffer = new IndexBuffer();
        m_indexBuffer->LoadBufferData(indices);
        
        m_positionModifier = new PositionModelviewModifier();
        SetModelviewModifier(m_positionModifier);
        
        m_attributeInitializer = new PositionNormalInitializer();
        m_cubemapUniformInitializer = new CubeMapUniformInitializer();
        m_projectionModelviewInitializer = new ProjectionModelviewInitializer();
        
        m_drawRequest = new VertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetRenderMode(RENDER_MODE_TRIANGLES);
        
        Projection projection(M_PI_2, 1.0f, 0.1f, 20.0f);
        m_cubeMapCamera = new CubeMapCamera(CSize(512, 512), projection, new Framebuffer(), new DepthRenderbufferCompontent16(), nullptr, PIXEL_FORMAT_RGBA, PIXEL_TYPE_UBYTE);
        m_cubeMapCamera->GetTextureCubeMap()->SetMinFilter(TEX_MIN_FILTER_NEAREST);
        m_cubeMapCamera->GetTextureCubeMap()->SetMagFilter(TEX_MAG_FILTER_NEAREST);
        RenderingEngine::SharedInstance().AddOffscreenCamera(m_cubeMapCamera);
    }
    
    GlassSphereDrawing::~GlassSphereDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_positionModifier;
        delete m_attributeInitializer;
        delete m_cubemapUniformInitializer;
        delete m_projectionModelviewInitializer;
        delete m_drawRequest;
        delete m_positionModifier;
        delete m_cubeMapCamera;
    }
    
    void GlassSphereDrawing::Draw(const Matrix4 &rProjectionMatrix) const {
        RenderingEngine::SharedInstance().Enable(SERVER_CAPABILITY_CULL_FACE);
        RenderingEngine::SharedInstance().Enable(SERVER_CAPABILITY_DEPTH_TEST);
        
        switch (m_drawingMode) {
            case GlassSphereDrawingMode::GlassSphereDrawingModeDefault: {
                m_drawRequest->SetUniformInitializer(m_cubemapUniformInitializer);
                m_cubemapUniformInitializer->SetProjectionMatrix(rProjectionMatrix);
                
                if (m_cubeMapCamera) {
                    m_cubeMapCamera->GetTextureCubeMap()->Bind();
                }
                
                Program *program = ProgramContainer::SharedInstance().GetGlassProgram();
                program->ExecuteDrawRequest(m_drawRequest);
                break;
            }
            case GlassSphereDrawingMode::GlassSphereDrawingModeFrontNormals: {
                m_drawRequest->SetUniformInitializer(m_projectionModelviewInitializer);
                m_projectionModelviewInitializer->SetProjectionMatrix(rProjectionMatrix);
                
                Program *program = ProgramContainer::SharedInstance().GetNormalTextureProgram();
                program->ExecuteDrawRequest(m_drawRequest);
                break;
            }
            case GlassSphereDrawingMode::GlassSphereDrawingModeBackNormals: {
                Program *program = ProgramContainer::SharedInstance().GetNormalTextureProgram();
                program->ExecuteDrawRequest(m_drawRequest);
                break;
            }
            case GlassSphereDrawingMode::GlassSphereDrawingModeDepth: {
                break;
            }
        }
    }
    
    PositionModelviewModifier * GlassSphereDrawing::GetPositionModelviewModifier() const {
        return m_positionModifier;
    }
    
    void GlassSphereDrawing::SetDrawingMode(GlassSphereDrawingMode mode) {
        m_drawingMode = mode;
    }
    
    GlassSphereDrawingMode GlassSphereDrawing::GetDrawingMode() const {
        return m_drawingMode;
    }
    
    void GlassSphereDrawing::Update(float interval) {
        m_cubemapUniformInitializer->SetModelviewMatrix(GetModelviewMatrix());
        m_cubemapUniformInitializer->SetNormalMatrix(GetModelviewMatrix().ToMatrix3());
        m_projectionModelviewInitializer->SetModelviewMatrix(GetModelviewMatrix());
        
        Point3 position = GetPositionModelviewModifier()->GetPosition();
        m_cubeMapCamera->SetLookAt(position, Point3(position.x, position.y, -100.0f), Vector3(0.0f, 1.0f, 0.0f));
    }
}