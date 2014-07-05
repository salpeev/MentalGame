//
//  Drawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingComponent.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class DrawingComposite: public DrawingComponent {
    public:
        DrawingComposite();
        ~DrawingComposite();
        
        void UpdateHierarchy(float interval);
        void DrawHierarchy(const Matrix4 &rProjectionMatrix) const;
        void Draw(const Matrix4 &rProjectionMatrix) const;
        DrawingComponent * HitTest(const Point3 &rPoint);
        
        void AddSubDrawing(DrawingComponent *pDrawing);
        void RemoveSubDrawing(DrawingComponent *pDrawing);
        
    protected:
        void Update(float interval);
        
    private:
        void UpdateSubDrawings(float interval);
        void DrawSubDrawings(const Matrix4 &rProjectionMatrix) const;
        
        vector<DrawingComponent *> *m_subDrawings;
    };
}
