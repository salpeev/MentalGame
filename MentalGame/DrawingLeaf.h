//
//  DrawingLeaf.h
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingComponent.h"



namespace Renderer {
    
    class DrawingLeaf: public DrawingComponent {
    public:
        void UpdateHierarchy(float interval);
        void DrawHierarchy(const Matrix4 &rProjectionMatrix) const;
        void Draw(const Matrix4 &rProjectionMatrix) const;
        DrawingComponent * HitTest(const Point3 &rPoint);
        
    protected:
        void Update(float interval);
    };
}
