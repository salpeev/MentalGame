//
//  AnimationDelegate.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 08.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "AnimationDelegate.h"
#include "Animation.h"



namespace Renderer {
    
    AnimationDelegate::AnimationDelegate() {
        m_animations = new vector<Animation *>;
    }
    
    AnimationDelegate::~AnimationDelegate() {
        for (int i = 0; i < m_animations->size(); i++) {
            Animation *pAnimation = m_animations->at(i);
            delete pAnimation;
        }
        
        delete m_animations;
    }
    
    void AnimationDelegate::AddAnimation(Animation *pAnimation) {
        pAnimation->SetAnimationDelegate(this);
        m_animations->push_back(pAnimation);
    }
    
    void AnimationDelegate::UpdateAnimations(float interval) {
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
    
    Point AnimationDelegate::GetPosition() const {
        return Point();
    }
    
    float AnimationDelegate::GetXRotation() const {
        return 0.0f;
    }
    
    float AnimationDelegate::GetYRotation() const {
        return 0.0f;
    }
    
    float AnimationDelegate::GetZRotation() const {
        return 0.0f;
    }
    
    Quaternion AnimationDelegate::GetQuaternion() const {
        return Quaternion();
    }
    
    
    void AnimationDelegate::SetPosition(const Point &rPosition) {
        
    }
    
    void AnimationDelegate::SetXRotation(float angle) {
        
    }
    
    void AnimationDelegate::SetYRotation(float angle) {
        
    }
    
    void AnimationDelegate::SetZRotation(float angle) {
        
    }
    
    void AnimationDelegate::SetQuaternion(const Quaternion &rQuaternion) {
        
    }
    
}