//
//  DrawingComponent.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Animation.h"
#include "TouchesHandler.h"
#include "ModelviewModifier.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class DrawingComposite;
    
    
    
    class DrawingComponent: public TouchesHandler {
    public:
        DrawingComponent();
        virtual ~DrawingComponent();
        
        virtual void UpdateHierarchy(float interval);
        virtual void DrawHierarchy(const Matrix4 &rProjectionMatrix) const = 0;
        virtual void Draw(const Matrix4 &rProjectionMatrix) const = 0;
        virtual bool PointInside(const Point3 &rPoint) const;
        virtual DrawingComponent * HitTest(const Point3 &rPoint) = 0;
        
        void AddAnimation(Animation *pAnimation);
        void UpdateAnimations(float interval);
        
        void RemoveFromParentDrawing();
        DrawingComposite * GetParentDrawing() const;
        
    protected:
        virtual void Update(float interval) = 0;
        
        friend class DrawingComposite;
        void SetParentDrawing(DrawingComposite *pDrawing);
        
        void SetModelviewModifier(ModelviewModifier *pModelviewModifier);
        ModelviewModifier *GetModelviewModifier() const;        // TODO: Should be model matrix
        Matrix4 GetModelviewMatrix() const;
        
    private:
        DrawingComposite *m_parentDrawing;
        ModelviewModifier *m_modelviewModifier;
        vector<Animation *> *m_animations;
    };
}
