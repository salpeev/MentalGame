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
#include <map>

using namespace std;



namespace Renderer {
    
    class RenderingEngine {
    public:
        static RenderingEngine & SharedInstance() {
            static RenderingEngine renderingEngine;
            return renderingEngine;
        }
        
        void SetFramebuffer(Framebuffer *pFramebuffer);
        Framebuffer * GetFramebuffer() const;
        
        void SetDrawingController(DrawingController *pDrawingController);
        DrawingController * GetDrawingController() const;
        
        void SetWindowSize(const CSize &rSize);
        CSize GetWindowSize() const;
        
        void SetProjection(const Projection &rProjection);
        Projection GetProjection() const;
        
        void SetRenderFrame(const Rect &rFrame) const;
        void ResetRenderFrame() const;
        Rect GetRenderFrame() const;
        
        void Render(float interval) const;
        
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
        
        CSize m_windowSize;
        Projection m_projection;
        Framebuffer *m_framebuffer;
        DrawingController *m_drawingController;
        vector<Touch *> *m_touches;
    };
}
