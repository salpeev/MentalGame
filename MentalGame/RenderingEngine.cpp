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
    RenderingEngine::RenderingEngine(): m_drawingController(nullptr) {
        m_touches = new vector<Touch *>;
        
        PrintExtensions();
    }
    
    RenderingEngine::~RenderingEngine() {
        delete m_drawingController;
        
        for (vector<Touch *>::iterator iterator = m_touches->begin(); iterator != m_touches->end(); iterator++) {
            delete *iterator;
        }
        delete m_touches;
    }
    
#pragma mark - Public Methods
    
    void RenderingEngine::SetMainCamera(Camera *pCamera) {
        if (m_mainCamera == pCamera) {
            return;
        }
        
        delete m_mainCamera;
        m_mainCamera = pCamera;
    }
    
    Camera * RenderingEngine::GetMainCamera() const {
        return m_mainCamera;
    }
    
    void RenderingEngine::AddOffscreenCamera(Camera *pCamera) {
        if (find(m_offscreenCameras.begin(), m_offscreenCameras.end(), pCamera) == m_offscreenCameras.end()) {
            m_offscreenCameras.push_back(pCamera);
        }
    }
    
    void RenderingEngine::RemoveOffscreenCamera(Camera *pCamera) {
        m_offscreenCameras.erase(remove(m_offscreenCameras.begin(), m_offscreenCameras.end(), pCamera), m_offscreenCameras.end());
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
    
    bool RenderingEngine::IsEnabled(SERVER_CAPABILITY serverCapability) const {
        bool isEnabled = glIsEnabled(serverCapability) == GLSL_TRUE;
        CheckError();
        return isEnabled;
    }
    
    void RenderingEngine::Enable(SERVER_CAPABILITY serverCapability) const {
        if (!IsEnabled(serverCapability)) {
            glEnable(serverCapability);
            CheckError();
        }
    }
    
    void RenderingEngine::Disable(SERVER_CAPABILITY serverCapability) const {
        if (IsEnabled(serverCapability)) {
            glDisable(serverCapability);
            CheckError();
        }
    }
    
    void RenderingEngine::SetFrontFace(FRONT_FACE frontFace) const {
        if (GetFrontFace() != frontFace) {
            glFrontFace(frontFace);
            CheckError();
        }
    }
    
    FRONT_FACE RenderingEngine::GetFrontFace() const {
        GLint frontFace;
        glGetIntegerv(GET_PARAMETER_FRONT_FACE, &frontFace);
        CheckError();
        return (FRONT_FACE)frontFace;
    }
    
    void RenderingEngine::SetCullFace(CULL_FACE cullFace) const {
        if (GetCullFace() != cullFace) {
            glCullFace(cullFace);
            CheckError();
        }
    }
    
    CULL_FACE RenderingEngine::GetCullFace() const {
        GLint cullFace;
        glGetIntegerv(GET_PARAMETER_CULL_FACE_MODE, &cullFace);
        CheckError();
        return (CULL_FACE)cullFace;
    }
    
    void RenderingEngine::Update(float interval) const {
        m_drawingController->GetDrawing()->UpdateHierarchy(interval);
    }
    
    void RenderingEngine::Render() const {
        for (Camera *pCamera : m_offscreenCameras) {
            DrawWithCamera(pCamera);
        }
        
        DrawWithCamera(m_mainCamera);
    }
    
    void RenderingEngine::RenderScene(const Matrix4 &rProjectionMatrix) const {
        GetDrawingController()->WillDrawDrawing();
        GetDrawingController()->GetDrawing()->DrawHierarchy(rProjectionMatrix);
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
    
    void RenderingEngine::PrintExtensions() const {
        string extensions = (const char *)glGetString(GL_EXTENSIONS);
        char *extensionStart = &extensions[0];
        char **extension = &extensionStart;
        Log("Supported OpenGL ES Extensions:");
        
        while(*extension) {
            Log("\t%s", strsep(extension, " "));
        }
        
        Log("");
    }
    
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
    
    void RenderingEngine::DrawWithCamera(Camera *pCamera) const {
        CSize resolution = pCamera->GetResolution();
        SetViewport(Rect(0.0f, 0.0f, resolution.width, resolution.height));
        
        pCamera->Record();
    }
}
