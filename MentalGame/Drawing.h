//
//  Drawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLDrawRequest.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class Drawing {
    public:
        Drawing();
        ~Drawing();
        
        void UpdateHierarchy(float interval);
        void DrawHierarchy() const;
        
        void AddSubDrawing(Drawing *pDrawing);
        void RemoveSubDrawing(Drawing *pDrawing);
        void RemoveFromParentDrawing();
        Drawing *GetParentDrawing() const;
        
    protected:
        virtual void Update(float interval);
        virtual void Draw() const;
        
    private:
        void UpdateSubDrawings(float interval);
        void DrawSubDrawings() const;
        void SetParentDrawing(Drawing *pDrawing);
        
        vector<Drawing *> *m_subDrawings;
        Drawing *m_parentDrawing;
    };
}
