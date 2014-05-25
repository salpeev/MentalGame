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
#include "TextureCamera.h"
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
        
        
        
        
        
        Projection projection(-2.0f, 2.0f, -2.0f, 2.0f, 4.0f, 10.0f, false);
        m_textureCamera = new TextureCamera(CSize(1024, 1024), projection, new Framebuffer(), new DepthRenderbufferCompontent16(), nullptr, PIXEL_FORMAT_RGBA, PIXEL_TYPE_USHORT_5_5_5_1);
        RenderingEngine::SharedInstance().AddOffscreenCamera(m_textureCamera);
        
        
        TextureCubeMap *cubeMap = new TextureCubeMap();
        for (int i = 0; i < 6; i++) {
            TextureImage textureImage(CSize(256, 256), PIXEL_FORMAT_RGBA, PIXEL_TYPE_USHORT_5_5_5_1);
//                        TextureImage *textureImage = ResourceManager::SharedInstance().LoadTexturePOT("globe.png");
            cubeMap->SetTextureImage(&textureImage, 0, TEXTURE_CUBE_MAP_SIDE(TEXTURE_CUBE_MAP_SIDE_POSITIVE_X + i));
//                        delete textureImage;
        }
    }
    
    GlassSphereDrawing::~GlassSphereDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_positionModifier;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_drawRequest;
        delete m_positionModifier;
        delete m_textureCamera;
    }
    
    PositionModelviewModifier * GlassSphereDrawing::GetPositionModelviewModifier() const {
        return m_positionModifier;
    }
    
    void GlassSphereDrawing::Update(float interval) {
        m_uniformInitializer->SetModelviewMatrix(GetModelviewMatrix());
        
//        Point3 position = GetPositionModelviewModifier()->GetPosition();
//        Matrix4 cameraFrustum = Matrix4::Frustum(M_PI_2, 1.0f, 1.0f, 20.0f);
//        Matrix4 cameraTranslation = Matrix4::Translation(-position.x, -position.y, -position.z);
//        
//        const Vector4 &rX = cameraFrustum.x;
//        const Vector4 &rY = cameraFrustum.y;
//        const Vector4 &rZ = cameraFrustum.z;
//        const Vector4 &rW = cameraFrustum.w;
//        
//        Matrix4 m0 = cameraTranslation * Matrix4(-rZ, -rY, -rX, rW);
//        Matrix4 m1 = cameraTranslation * Matrix4( rZ, -rY,  rX, rW);
//        Matrix4 m2 = cameraTranslation * Matrix4( rX, -rZ,  rY, rW);
//        Matrix4 m3 = cameraTranslation * Matrix4( rX,  rZ, -rY, rW);
//        Matrix4 m4 = cameraTranslation * Matrix4( rX, -rY, -rZ, rW);
//        Matrix4 m5 = cameraTranslation * Matrix4(-rX, -rY,  rZ, rW);
    }
    
    void GlassSphereDrawing::Draw() const {
        Program *program = ProgramContainer::SharedInstance().GetPerspectiveProgram();
        program->ExecuteDrawRequest(m_drawRequest);
    }
}