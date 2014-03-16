//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RenderingEngine.h"
#include "Logger.h"
#include "GLConstants.h"



namespace Renderer {
    
#pragma mark - Lifecycle
    
    RenderingEngine::RenderingEngine(): m_framebuffer(nullptr), m_drawingController(nullptr), m_windowSize(0.0f, 0.0f) {
        
    }
    
    RenderingEngine::~RenderingEngine() {
        delete m_drawingController;
    }
    
#pragma mark - Public Methods
    
    void RenderingEngine::SetFramebuffer(Framebuffer *pFramebuffer) {
        m_framebuffer = pFramebuffer;
    }
    
    Framebuffer * RenderingEngine::GetFramebuffer() const {
        return m_framebuffer;
    }
    
    void RenderingEngine::SetDrawingController(DrawingController *pDrawingController) {
        delete m_drawingController;
        m_drawingController = pDrawingController;
    }
    
    DrawingController * RenderingEngine::GetDrawingController() const {
        return m_drawingController;
    }
    
    void RenderingEngine::SetWindowSize(const CSize &rSize) {
        m_windowSize = rSize;
        ResetRenderFrame();
    }
    
    CSize RenderingEngine::GetWindowSize() const {
        return m_windowSize;
    }
    
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
    
    void RenderingEngine::Render(float interval) const {
        m_framebuffer->Clear();
        
        m_drawingController->GetDrawing()->UpdateHierarchy(interval);
        m_drawingController->GetDrawing()->DrawHierarchy();
    }
    
//#pragma mark Touches
//    
//    void RenderingEngine::TouchesBegan(vector<Touch> &rTouches) const {
//        
//    }
//    
//    void RenderingEngine::TouchesMoved(vector<Touch> &rTouches) const {
//        
//    }
//    
//    void RenderingEngine::TouchesEnded(vector<Touch> &rTouches) const {
//        
//    }
//    
//    void RenderingEngine::TouchesCancelled(vector<Touch> &rTouches) const {
//        
//    }
}
