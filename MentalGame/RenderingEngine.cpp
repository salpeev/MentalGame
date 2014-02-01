//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RenderingEngine.h"



namespace Renderer {
    
#pragma mark - Lifecycle
    
    RenderingEngine::RenderingEngine(Framebuffer *pFramebuffer, int width, int height): m_framebuffer(pFramebuffer), m_windowSize(width, height) {
        
    }
    
    RenderingEngine::~RenderingEngine() {
        
    }
    
#pragma mark - Public Methods
    
    void RenderingEngine::Render() const {
        m_framebuffer->Clear();
    }
}
