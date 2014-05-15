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
        Touch(Point2 windowPosition, void *pSystemTouch);
        ~Touch();
        
        void SetWindowPosition(const Point2 &rPosition);
        void SetDrawingComponent(DrawingComponent *pDrawingComponent);
        
        Point2 GetWindowPosition() const;
        DrawingComponent * GetDrawingComponent() const;
        void * GetSystemTouch() const;
        Point3 GetProjectionPosition() const;
        
    private:
        Point2 m_windowPosition;
        DrawingComponent *m_drawingComponent;
        void *m_systemTouch;
    };
}
