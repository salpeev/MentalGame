//
//  GameDrawingController.h
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingController.h"



namespace Renderer {
    
    class GlassSphereDrawing;
    class VertexBuffer;
    class IndexBuffer;
    class TextureCamera;
    class BufferCamera;
    
    
    
    class GameDrawingController: public DrawingController {
    public:
        GameDrawingController();
        ~GameDrawingController();
        
        void WillDrawDrawing();
        
    private:
        void CreatePhotoMap(int width, int height);
        void CreateCameras();
        
        vector<GlassSphereDrawing *> m_glassDrawings;
        vector<DrawingComponent *> m_sceneDrawings;
        VertexBuffer *m_photoMapVertexBuffer;
        IndexBuffer *m_photoMapIndexBuffer;
        TextureCamera *m_frontNormalsDepthCamera;
        TextureCamera *m_backNormalsDepthCamera;
        BufferCamera *m_sceneDepthCamera;
    };
}