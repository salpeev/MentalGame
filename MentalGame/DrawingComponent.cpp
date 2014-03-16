//
//  DrawingComponent.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingComponent.h"
#include "DrawingComposite.h"



namespace Renderer {
    
    DrawingComponent::DrawingComponent() {
        
    }
    
    DrawingComponent::~DrawingComponent() {
        
    }
    
#pragma mark - Public Methods
    
    void DrawingComponent::UpdateHierarchy(float interval) {
        UpdateAnimations(interval);
    }
    
    void DrawingComponent::RemoveFromParentDrawing() {
        m_parentDrawing->RemoveSubDrawing(this);
    }
    
    DrawingComposite * DrawingComponent::GetParentDrawing() const {
        return m_parentDrawing;
    }
    
#pragma mark - Protected Methods
    
    void DrawingComponent::SetParentDrawing(DrawingComposite *pDrawing) {
        m_parentDrawing = pDrawing;
        SetNextTouchesHandler(pDrawing);
    }
}
