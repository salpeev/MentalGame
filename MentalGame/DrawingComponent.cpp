//
//  DrawingComponent.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingComponent.h"
#include "CompositeDrawing.h"
#include "Animation.h"



namespace Renderer {
    
    DrawingComponent::DrawingComponent() {
        m_animations = new vector<Animation *>;
    }
    
    DrawingComponent::~DrawingComponent() {
        for (int i = 0; i < m_animations->size(); i++) {
            Animation *pAnimation = m_animations->at(i);
            delete pAnimation;
        }
        
        delete m_animations;
    }
    
#pragma mark - Public Methods
    
    void DrawingComponent::UpdateHierarchy(float interval) {
        UpdateAnimations(interval);
    }
    
    void DrawingComponent::RemoveFromParentDrawing() {
        m_parentDrawing->RemoveSubDrawing(this);
    }
    
    CompositeDrawing * DrawingComponent::GetParentDrawing() const {
        return m_parentDrawing;
    }
    
    void DrawingComponent::AddAnimation(Animation *pAnimation) {
        m_animations->push_back(pAnimation);
    }
    
#pragma mark - Protected Methods
    
    void DrawingComponent::UpdateAnimations(float interval) {
        // TODO: Test
        vector<Animation *> finishedAnimations;
        
        for (int i = 0; i < m_animations->size(); i++) {
            Animation *pAnimation = m_animations->at(i);
            pAnimation->Update(interval);
            
            if (pAnimation->IsFinished()) {
                finishedAnimations.push_back(pAnimation);
            }
        }
        
        for (vector<Animation *>::iterator iterator = finishedAnimations.begin(); iterator != finishedAnimations.end(); iterator++) {
            Animation *pAnimation = *iterator;
            if (pAnimation->IsFinished()) {
                m_animations->erase(remove(m_animations->begin(), m_animations->end(), *iterator));
                delete *iterator;
            }
        }
    }
    
    void DrawingComponent::SetParentDrawing(CompositeDrawing *pDrawing) {
        m_parentDrawing = pDrawing;
    }
}
