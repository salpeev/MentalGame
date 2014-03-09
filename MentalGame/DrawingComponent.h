//
//  DrawingComponent.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "AnimationDelegate.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class CompositeDrawing;
    class Animation;
    
    
    
    class DrawingComponent: public AnimationDelegate {
    public:
        DrawingComponent();
        virtual ~DrawingComponent();
        
        virtual void UpdateHierarchy(float interval);
        virtual void DrawHierarchy() const = 0;
        
        void RemoveFromParentDrawing();
        CompositeDrawing * GetParentDrawing() const;
        
        void AddAnimation(Animation *pAnimation);
        
    protected:
        virtual void Update(float interval) = 0;
        virtual void Draw() const = 0;
        
        void UpdateAnimations(float interval);
        
        friend class CompositeDrawing;
        void SetParentDrawing(CompositeDrawing *pDrawing);
        
    private:
        CompositeDrawing *m_parentDrawing;
        vector<Animation *> *m_animations;
    };
}
