//
//  GameDrawingController.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GameDrawingController.h"
#include "TextureDrawing.h"
#include "ColorGlassDrawing.h"
#include "SegmentDrawing.h"
#include "ResourceManager.h"
#include "RoomDrawing.h"
#include "GlassSphereDrawing.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Logger.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "TextureCamera.h"
#include "DepthRenderbufferComponent16.h"
#include "RenderingEngine.h"



namespace Renderer {
    
    GameDrawingController::GameDrawingController() {
        // TODO: Memory management
        RoomDrawing *roomDrawing = new RoomDrawing();
        GetDrawing()->AddSubDrawing(roomDrawing);
        
//        TextureDrawing *textureDrawing = new TextureDrawing();
//        GetDrawing()->AddSubDrawing(textureDrawing);
        
        ColorGlassDrawing *colorGlassDrawing = new ColorGlassDrawing();
        colorGlassDrawing->GetPositionModelviewModifier()->SetPosition(Point3(0.0f, -1.0f, -8.5f));
        GetDrawing()->AddSubDrawing(colorGlassDrawing);
        
//        SegmentDrawing *segmentDrawing = new SegmentDrawing();
//        segmentDrawing->SetStartPoint(Point3(-1.5, -1.5, -4));
//        segmentDrawing->SetEndPoint(Point3(1.5, 1.5, -5));
//        GetDrawing()->AddSubDrawing(segmentDrawing);
        
        GlassSphereDrawing *glassSphereDrawing0 = new GlassSphereDrawing();
        glassSphereDrawing0->GetPositionModelviewModifier()->SetPosition(Point3(-2.0f, -2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing0);

        GlassSphereDrawing *glassSphereDrawing1 = new GlassSphereDrawing();
        glassSphereDrawing1->GetPositionModelviewModifier()->SetPosition(Point3(2.0f, -2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing1);
        
        GlassSphereDrawing *glassSphereDrawing2 = new GlassSphereDrawing();
        glassSphereDrawing2->GetPositionModelviewModifier()->SetPosition(Point3(2.0f, 2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing2);
        
        GlassSphereDrawing *glassSphereDrawing3 = new GlassSphereDrawing();
        glassSphereDrawing3->GetPositionModelviewModifier()->SetPosition(Point3(-2.0f, 2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing3);
        
        GlassSphereDrawing *glassSphereDrawing4 = new GlassSphereDrawing();
        glassSphereDrawing4->GetPositionModelviewModifier()->SetPosition(Point3(0.0f, 0.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing4);
        
        m_glassDrawings.push_back(glassSphereDrawing0);
        m_glassDrawings.push_back(glassSphereDrawing1);
        m_glassDrawings.push_back(glassSphereDrawing2);
        m_glassDrawings.push_back(glassSphereDrawing3);
        m_glassDrawings.push_back(glassSphereDrawing4);
        
        CreatePhotoMap(1024, 1024);
        CreateCameras();
    }
    
    GameDrawingController::~GameDrawingController() {
        delete m_photoMapVertexBuffer;
        delete m_photoMapIndexBuffer;
    }
    
    void GameDrawingController::WillDrawDrawing() {
        
    }
    
    void GameDrawingController::CreatePhotoMap(int width, int height) {
        int numPhotons = width * height;
        Vector2 texel(1.0f / width, 1.0f / height);
        Vector2 dxdy(0.5f / width, 0.5f / height);
        
        vector<Vector2> photons(numPhotons);
        vector<GLushort> indices(numPhotons);
        
        GLushort k = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                photons[k] = Vector2(texel.x * j, texel.y * i) + dxdy;
                indices[k] = k;
                k++;
            }
        }
        
        m_photoMapVertexBuffer = new VertexBuffer();
        m_photoMapVertexBuffer->LoadBufferData(&photons[0], sizeof(Vector2), numPhotons);
        
        m_photoMapIndexBuffer = new IndexBuffer();
        m_photoMapIndexBuffer->LoadBufferData(indices);
    }
    
    void GameDrawingController::CreateCameras() {
        Projection projection(M_PI_2, 1.0f, 1.0f, 100.0f);
        m_frontNormalsDepthCamera = new TextureCamera(CSize(512, 512), projection, new Framebuffer(), new DepthRenderbufferCompontent16(), nullptr, PIXEL_FORMAT_RGBA, PIXEL_TYPE_UBYTE);
        m_frontNormalsDepthCamera->SetLookAt(Point3(1.0f, 1.0f, 0.0f), Point3(0.0f, 0.0f, -100.0f), Vector3(0.1f, 1.0f, 0.1f));
        
        function<void (const Matrix4 &rProjectionMatrix)> drawingCallback = [this](const Matrix4 &rProjectionMatrix) {
            for (GlassSphereDrawing *glassSphereDrawing : m_glassDrawings) {
                glassSphereDrawing->Draw(rProjectionMatrix);
            }
        };
        m_frontNormalsDepthCamera->SetDrawingCallback(drawingCallback);
        
        RenderingEngine::SharedInstance().AddOffscreenCamera(m_frontNormalsDepthCamera);
    }
}






