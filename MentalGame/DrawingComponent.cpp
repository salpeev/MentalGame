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
    
    DrawingComponent::DrawingComponent(): m_parentDrawing(nullptr), m_modelviewModifier(nullptr) {
        m_animations = new vector<Animation *>;
    }
    
    DrawingComponent::~DrawingComponent() {
        delete m_modelviewModifier;
        
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
    
    void DrawingComponent::AddAnimation(Animation *pAnimation) {
        m_animations->push_back(pAnimation);
    }
    
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
    
    void DrawingComponent::SetModelviewModifier(ModelviewModifier *pModelviewModifier) {
        delete m_modelviewModifier;
        m_modelviewModifier = pModelviewModifier;
    }
    
    ModelviewModifier * DrawingComponent::GetModelviewModifier() const {
        return m_modelviewModifier;
    }
    
    Matrix4 DrawingComponent::GetModelviewMatrix() const {
        Matrix4 parentMatrix;
        if (GetParentDrawing()) {
            parentMatrix = GetParentDrawing()->GetModelviewMatrix();
        }
        
        Matrix4 currentMatrix;
        if (m_modelviewModifier) {
            currentMatrix = m_modelviewModifier->GetModelviewMatrix();
        }
        
        Matrix4 modelviewMatrix = parentMatrix * currentMatrix;
        return modelviewMatrix;
    }
}
