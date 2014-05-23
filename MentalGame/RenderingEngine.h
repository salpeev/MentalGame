//
//  RenderingEngine.h
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Framebuffer.h"
#include "Size.h"
#include "Rect.h"
#include "Touch.h"
#include "Projection.h"
#include "DrawingController.h"
#include "Constants.h"
#include "Camera.h"
#include <map>

using namespace std;



namespace Renderer {
    
    class RenderingEngine {
    public:
        static RenderingEngine & SharedInstance() {
            static RenderingEngine renderingEngine;
            return renderingEngine;
        }
        
        void SetCamera(Camera *pCamera);
        Camera * GetCamera() const;
        
        void SetDrawingController(DrawingController *pDrawingController);
        DrawingController * GetDrawingController() const;
        
        void SetViewport(const Rect &rViewport) const;
        Rect GetViewport() const;
        
        void Enable(SERVER_CAPABILITY serverCapability) const;
        void Disable(SERVER_CAPABILITY serverCapability) const;
        
        void Update(float interval) const;
        void Render() const;
        
        // Touches
        Touch * GetTouchForSystemTouch(const void *pSystemTouch) const;
        void HandleTouchesBegan(vector<Touch *> &rTouches) const;
        void HandleTouchesMoved(vector<Touch *> &rTouches) const;
        void HandleTouchesEnded(vector<Touch *> &rTouches) const;
        void HandleTouchesCancelled(vector<Touch *> &rTouches) const;
        
    private:
        RenderingEngine();
        RenderingEngine(const RenderingEngine &rRenderingEngine) = delete;
        ~RenderingEngine();
        RenderingEngine & operator= (const RenderingEngine &rRenderingEngine) = delete;
        
        map<DrawingComponent *, vector<Touch *>> SortTouchesByDrawingComponent(vector<Touch *> &rTouches) const;
        
        Camera *m_camera;
        DrawingController *m_drawingController;
        vector<Touch *> *m_touches;
    };
}
