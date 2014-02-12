//
//  DrawingComponent.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once



namespace Renderer {
    
    class CompositeDrawing;
    
    
    
    class DrawingComponent {
    public:
        virtual void UpdateHierarchy(float interval) = 0;
        virtual void DrawHierarchy() const = 0;
        
        void RemoveFromParentDrawing();
        
        void SetParentDrawing(CompositeDrawing *pDrawing);  // TODO: How this can be moved from public to protected?
        CompositeDrawing * GetParentDrawing() const;
        
    protected:
        virtual void Update(float interval) = 0;
        virtual void Draw() const = 0;
        
    private:
        CompositeDrawing *m_parentDrawing;
    };
}
