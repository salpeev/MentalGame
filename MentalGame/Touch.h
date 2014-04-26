//
//  Touch.h
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"



namespace Renderer {
    
    class DrawingComponent;
    
    
    
    class Touch {
    public:
        Touch(Point windowPosition, void *pSystemTouch);
        ~Touch();
        
        void SetWindowPosition(const Point &rPosition);
        void SetDrawingComponent(DrawingComponent *pDrawingComponent);
        
        Point GetWindowPosition() const;
        DrawingComponent * GetDrawingComponent() const;
        void * GetSystemTouch() const;
        Point GetProjectionPosition() const;
        
    private:
        Point m_windowPosition;
        DrawingComponent *m_drawingComponent;
        void *m_systemTouch;
    };
}
