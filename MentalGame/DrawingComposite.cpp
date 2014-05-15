//
//  DrawingComposite.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingComposite.h"
#include "AttributeInitializer.h"
#include "UniformInitializer.h"
#include "DrawRequest.h"



namespace Renderer {
    
#pragma mark - Lifecycle
    
    DrawingComposite::DrawingComposite() {
        m_subDrawings = new vector<DrawingComponent *>();
    }
    
    DrawingComposite::~DrawingComposite() {
        delete m_subDrawings;
    }
    
#pragma mark - Public Methods
    
    void DrawingComposite::UpdateHierarchy(float interval) {
        DrawingComponent::UpdateHierarchy(interval);
        Update(interval);
        UpdateSubDrawings(interval);
    }
    
    void DrawingComposite::DrawHierarchy() const {
        Draw();
        DrawSubDrawings();
    }
    
    DrawingComponent * DrawingComposite::HitTest(const Point3 &rPoint) {
        // TODO: Probably rewrite this method to take into account hit coordinate, not just subdrawing position in hierarchy
        if (!PointInside(rPoint)) {
            return nullptr;
        }
        
        for (int subdrawingIndex = m_subDrawings->size() - 1; subdrawingIndex >= 0; subdrawingIndex--) {
            DrawingComponent *subDrawing = m_subDrawings->at(subdrawingIndex);
            DrawingComponent *hitDrawing = subDrawing->HitTest(rPoint);
            
            if (hitDrawing) {
                return hitDrawing;
            }
        }
        
        return this;
    }
    
    void DrawingComposite::AddSubDrawing(DrawingComponent *pDrawing) {
        m_subDrawings->push_back(pDrawing);
        pDrawing->SetParentDrawing(this);
    }
    
    void DrawingComposite::RemoveSubDrawing(DrawingComponent *pDrawing) {
        // TODO: Should be tested. What if element doesn't exists? Is removed properly?
        m_subDrawings->erase(find(m_subDrawings->begin(), m_subDrawings->end(), pDrawing));
        pDrawing->SetParentDrawing(nullptr);
    }
    
#pragma mark - Protected Methods
    
    void DrawingComposite::Update(float interval) {
        
    }
    
    void DrawingComposite::Draw() const {
        
    }
    
#pragma mark - Private Methods
    
    void DrawingComposite::UpdateSubDrawings(float interval) {
        for (int subdrawingIndex = 0; subdrawingIndex < m_subDrawings->size(); subdrawingIndex++) {
            DrawingComponent *subdrawing = m_subDrawings->at(subdrawingIndex);
            subdrawing->UpdateHierarchy(interval);
        }
    }
    
    void DrawingComposite::DrawSubDrawings() const {
        for (int subdrawingIndex = 0; subdrawingIndex < m_subDrawings->size(); subdrawingIndex++) {
            DrawingComponent *subdrawing = m_subDrawings->at(subdrawingIndex);
            subdrawing->DrawHierarchy();
        }
    }
}