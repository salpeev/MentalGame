//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RenderingEngine.h"
#include "GLLogger.h"
#include "ColorGlassDrawing.h"  // TODO: Remove later



namespace Renderer {
    
#pragma mark - Lifecycle
    
    RenderingEngine::RenderingEngine(Framebuffer *pFramebuffer, int width, int height): m_framebuffer(pFramebuffer), m_windowSize(width, height) {
        ResetRenderFrame();
        
        m_rootDrawing = new Drawing();
        
        // TODO: Remove later
        ColorGlassDrawing *drawing = new ColorGlassDrawing();
        m_rootDrawing->AddSubDrawing(drawing);
    }
    
    RenderingEngine::~RenderingEngine() {
        delete m_rootDrawing;
    }
    
#pragma mark - Public Methods
    
    void RenderingEngine::SetRenderFrame(const Rect &rFrame) const {
        // TODO: GL_MAX_VIEWPORT_DIMS
        glViewport(rFrame.x, rFrame.y, rFrame.width, rFrame.height);
        CheckError();
    }
    
    void RenderingEngine::ResetRenderFrame() const {
        Rect renderFrame(0.0f, 0.0f, m_windowSize.width, m_windowSize.height);
        SetRenderFrame(renderFrame);
    }
    
    Rect RenderingEngine::GetRenderFrame() const {
        Rect renderFrame;
        glGetFloatv(GET_PARAMETER_VIEWPORT, (GLfloat *)(&renderFrame));
        CheckError();
        
        return renderFrame;
    }
    
    void RenderingEngine::Render() const {
        m_framebuffer->Clear();
        
        m_rootDrawing->DrawHierarchy();
    }
}
