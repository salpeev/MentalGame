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
        void DrawHierarchy() const;
        DrawingComponent * HitTest(const Point &rPoint);
        
        void AddSubDrawing(DrawingComponent *pDrawing);
        void RemoveSubDrawing(DrawingComponent *pDrawing);
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        void UpdateSubDrawings(float interval);
        void DrawSubDrawings() const;
        
        vector<DrawingComponent *> *m_subDrawings;
    };
}
