//
//  Drawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Drawing.h"
#include "GLSLAttributeInitializer.h"
#include "GLSLUniformInitializer.h"
#include "GLSLDrawRequest.h"



namespace Renderer {
    
#pragma mark - Lifecycle
    
    Drawing::Drawing() {
        m_subDrawings = new vector<Drawing *>();
    }
    
    Drawing::~Drawing() {
        delete m_subDrawings;
    }
    
#pragma mark - Public Methods
    
    void Drawing::DrawHierarchy() const {
        Draw();
        DrawSubDrawings();
    }
    
    void Drawing::AddSubDrawing(Drawing *pDrawing) {
        m_subDrawings->push_back(pDrawing);
        pDrawing->SetParentDrawing(this);
    }
    
    void Drawing::RemoveSubDrawing(Drawing *pDrawing) {
        // TODO: Should be tested. What if element doesn't exists? Is removed properly?
        m_subDrawings->erase(find(m_subDrawings->begin(), m_subDrawings->end(), pDrawing));
        pDrawing->SetParentDrawing(nullptr);
    }
    
    void Drawing::RemoveFromParentDrawing() {
        m_parentDrawing->RemoveSubDrawing(this);
    }
    
    Drawing * Drawing::GetParentDrawing() const {
        return m_parentDrawing;
    }
    
#pragma mark - Public Virtual Methods
    
    void Drawing::Draw() const {
        
    }
    
#pragma mark - Private Methods
    
    void Drawing::DrawSubDrawings() const {
        for (int subdrawingIndex = 0; subdrawingIndex < m_subDrawings->size(); subdrawingIndex++) {
            Drawing *subdrawing = m_subDrawings->at(subdrawingIndex);
            subdrawing->DrawHierarchy();
        }
    }
    
    void Drawing::SetParentDrawing(Drawing *pDrawing) {
        m_parentDrawing = pDrawing;
    }
}