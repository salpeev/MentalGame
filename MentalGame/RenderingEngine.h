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
#include "Drawing.h"
#include "Rect.h"



namespace Renderer {
    
    class RenderingEngine {
    public:
        static RenderingEngine & SharedInstance() {
            static RenderingEngine renderingEngine;
            return renderingEngine;
        }
        
        void SetFramebuffer(Framebuffer *pFramebuffer);
        Framebuffer * GetFramebuffer() const;
        
        void SetWindowSize(const CSize &rSize);
        CSize GetWindowSize() const;
        
        void SetRenderFrame(const Rect &rFrame) const;
        void ResetRenderFrame() const;
        Rect GetRenderFrame() const;
        
        void Render(float interval) const;
        
    private:
        RenderingEngine();
        RenderingEngine(const RenderingEngine &rRenderingEngine) = delete;
        ~RenderingEngine();
        RenderingEngine & operator= (const RenderingEngine &rRenderingEngine) = delete;
        
        Framebuffer *m_framebuffer;
        Drawing *m_rootDrawing;
        CSize m_windowSize;
    };
}
