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



namespace Renderer {
    
    class RenderingEngine {
    public:
        RenderingEngine(Framebuffer *pFramebuffer, int width, int height);
        RenderingEngine(const RenderingEngine &rRenderingEngine) = delete;
        ~RenderingEngine();
        
        void Render() const;
        
    private:
        Framebuffer *m_framebuffer;
        Size m_windowSize;
    };
}
