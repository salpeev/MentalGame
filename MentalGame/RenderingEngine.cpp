//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RenderingEngine.h"
#include "Logger.h"
#include "Constants.h"



namespace Renderer {
    
#pragma mark - Lifecycle
    
    // TODO: Size has default constructor, that initializes to 0. Is initialization required here?
    RenderingEngine::RenderingEngine(): m_camera(nullptr), m_drawingController(nullptr) {
        m_touches = new vector<Touch *>;
    }
    
    RenderingEngine::~RenderingEngine() {
        delete m_camera;
        delete m_drawingController;
        
        for (vector<Touch *>::iterator iterator = m_touches->begin(); iterator != m_touches->end(); iterator++) {
            delete *iterator;
        }
        delete m_touches;
    }
    
#pragma mark - Public Methods
    
    void RenderingEngine::SetCamera(Camera *pCamera) {
        if (m_camera == pCamera) {
            return;
        }
        
        delete m_camera;
        m_camera = pCamera;
        m_camera->Initialize();
    }
    
    Camera * RenderingEngine::GetCamera() const {
        return m_camera;
    }
    
    void RenderingEngine::SetDrawingController(DrawingController *pDrawingController) {
        delete m_drawingController;
        m_drawingController = pDrawingController;
    }
    
    DrawingController * RenderingEngine::GetDrawingController() const {
        return m_drawingController;
    }
    
    void RenderingEngine::SetViewport(const Rect &rViewport) const {
        glViewport(rViewport.origin.x, rViewport.origin.y, rViewport.size.width, rViewport.size.height);
        CheckError();
    }
    
    Rect RenderingEngine::GetViewport() const {
        Rect viewport;
        glGetFloatv(GET_PARAMETER_VIEWPORT, (float *)(&viewport));
        CheckError();
        
        return viewport;
    }
    
    void RenderingEngine::Enable(SERVER_CAPABILITY serverCapability) const {
        if (glIsEnabled(serverCapability) == GLSL_FALSE) {
            glEnable(serverCapability);
            CheckError();
        }
    }
    
    void RenderingEngine::Disable(SERVER_CAPABILITY serverCapability) const {
        if (glIsEnabled(serverCapability) == GLSL_TRUE) {
            glDisable(serverCapability);
            CheckError();
        }
    }
    
    void RenderingEngine::Update(float interval) const {
        m_drawingController->GetDrawing()->UpdateHierarchy(interval);
    }
    
    void RenderingEngine::Render() const {
        m_camera->Enable();
        m_drawingController->GetDrawing()->DrawHierarchy();
    }
    
#pragma mark Touches
    
    Touch * RenderingEngine::GetTouchForSystemTouch(const void *pSystemTouch) const {
        for (int touchIndex = 0; touchIndex < m_touches->size(); touchIndex++) {
            Touch *touch = m_touches->at(touchIndex);
            if (touch->GetSystemTouch() == pSystemTouch) {
                return touch;
            }
        }
        
        return nullptr;
    }
    
    void RenderingEngine::HandleTouchesBegan(vector<Touch *> &rTouches) const {
        m_touches->insert(m_touches->end(), rTouches.begin(), rTouches.end());
        
        for (int touchIndex = 0; touchIndex < rTouches.size(); touchIndex++) {
            Touch *touch = rTouches[touchIndex];
            Point3 touchPosition = touch->GetProjectionPosition();
            DrawingComponent *hitDrawing = m_drawingController->GetDrawing()->HitTest(touchPosition);
            touch->SetDrawingComponent(hitDrawing);
        }
        
        map<DrawingComponent *, vector<Touch *>> sortedTouches = SortTouchesByDrawingComponent(rTouches);
        
        for (map<DrawingComponent *, vector<Touch *>>::iterator iterator = sortedTouches.begin(); iterator != sortedTouches.end(); iterator++) {
            DrawingComponent *pDrawing = iterator->first;
            vector<Touch *> &rDrawingTouches = iterator->second;
            pDrawing->TouchesBegan(rDrawingTouches);
        }
    }
    
    void RenderingEngine::HandleTouchesMoved(vector<Touch *> &rTouches) const {
        map<DrawingComponent *, vector<Touch *>> sortedTouches = SortTouchesByDrawingComponent(rTouches);
        
        for (map<DrawingComponent *, vector<Touch *>>::iterator iterator = sortedTouches.begin(); iterator != sortedTouches.end(); iterator++) {
            DrawingComponent *pDrawing = iterator->first;
            vector<Touch *> &rDrawingTouches = iterator->second;
            pDrawing->TouchesMoved(rDrawingTouches);
        }
    }
    
    void RenderingEngine::HandleTouchesEnded(vector<Touch *> &rTouches) const {
        map<DrawingComponent *, vector<Touch *>> sortedTouches = SortTouchesByDrawingComponent(rTouches);
        
        for (map<DrawingComponent *, vector<Touch *>>::iterator iterator = sortedTouches.begin(); iterator != sortedTouches.end(); iterator++) {
            DrawingComponent *pDrawing = iterator->first;
            vector<Touch *> &rDrawingTouches = iterator->second;
            pDrawing->TouchesEnded(rDrawingTouches);
        }
        
        for (int touchIndex = 0; touchIndex < rTouches.size(); touchIndex++) {
            Touch *touch = rTouches[touchIndex];
            m_touches->erase(remove(m_touches->begin(), m_touches->end(), touch));
        }
    }
    
    void RenderingEngine::HandleTouchesCancelled(vector<Touch *> &rTouches) const {
        map<DrawingComponent *, vector<Touch *>> sortedTouches = SortTouchesByDrawingComponent(rTouches);
        
        for (map<DrawingComponent *, vector<Touch *>>::iterator iterator = sortedTouches.begin(); iterator != sortedTouches.end(); iterator++) {
            DrawingComponent *pDrawing = iterator->first;
            vector<Touch *> &rDrawingTouches = iterator->second;
            pDrawing->TouchesCancelled(rDrawingTouches);
        }
        
        for (int touchIndex = 0; touchIndex < rTouches.size(); touchIndex++) {
            Touch *touch = rTouches[touchIndex];
            m_touches->erase(remove(m_touches->begin(), m_touches->end(), touch));
        }
    }
    
#pragma mark - Private Methods
    
    map<DrawingComponent *, vector<Touch *>> RenderingEngine::SortTouchesByDrawingComponent(vector<Touch *> &rTouches) const {
        map<DrawingComponent *, vector<Touch *>> sortedTouches;
        for (int touchIndex = 0; touchIndex < rTouches.size(); touchIndex++) {
            Touch *touch = rTouches[touchIndex];
            DrawingComponent *pDrawing = touch->GetDrawingComponent();
            
            vector<Touch *> &rDrawingTouches = sortedTouches[pDrawing];
            rDrawingTouches.push_back(touch);
        }
        return sortedTouches;
    }
}
