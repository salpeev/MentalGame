//
//  CompositeDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "CompositeDrawing.h"
#include "GLSLAttributeInitializer.h"
#include "GLSLUniformInitializer.h"
#include "GLSLDrawRequest.h"



namespace Renderer {
    
#pragma mark - Lifecycle
    
    CompositeDrawing::CompositeDrawing() {
        m_subDrawings = new vector<DrawingComponent *>();
    }
    
    CompositeDrawing::~CompositeDrawing() {
        delete m_subDrawings;
    }
    
#pragma mark - Public Methods
    
    void CompositeDrawing::UpdateHierarchy(float interval) {
        Update(interval);
        UpdateSubDrawings(interval);
    }
    
    void CompositeDrawing::DrawHierarchy() const {
        Draw();
        DrawSubDrawings();
    }
    
    void CompositeDrawing::AddSubDrawing(DrawingComponent *pDrawing) {
        m_subDrawings->push_back(pDrawing);
        pDrawing->SetParentDrawing(this);
    }
    
    void CompositeDrawing::RemoveSubDrawing(DrawingComponent *pDrawing) {
        // TODO: Should be tested. What if element doesn't exists? Is removed properly?
        m_subDrawings->erase(find(m_subDrawings->begin(), m_subDrawings->end(), pDrawing));
        pDrawing->SetParentDrawing(nullptr);
    }
    
#pragma mark - Protected Methods
    
    void CompositeDrawing::Update(float interval) {
        
    }
    
    void CompositeDrawing::Draw() const {
        
    }
    
#pragma mark - Private Methods
    
    void CompositeDrawing::UpdateSubDrawings(float interval) {
        for (int subdrawingIndex = 0; subdrawingIndex < m_subDrawings->size(); subdrawingIndex++) {
            DrawingComponent *subdrawing = m_subDrawings->at(subdrawingIndex);
            subdrawing->UpdateHierarchy(interval);
        }
    }
    
    void CompositeDrawing::DrawSubDrawings() const {
        for (int subdrawingIndex = 0; subdrawingIndex < m_subDrawings->size(); subdrawingIndex++) {
            DrawingComponent *subdrawing = m_subDrawings->at(subdrawingIndex);
            subdrawing->DrawHierarchy();
        }
    }
}