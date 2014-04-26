//
//  Touch.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Touch.h"
#include "RenderingEngine.h"
#include "DrawingComponent.h"



namespace Renderer {
    
    Touch::Touch(Point windowPosition, void *pSystemTouch): m_windowPosition(windowPosition), m_systemTouch(pSystemTouch) {
        
    }
    
    Touch::~Touch() {
        
    }
    
    void Touch::SetWindowPosition(const Point &rPosition) {
        m_windowPosition = rPosition;
    }
    
    void Touch::SetDrawingComponent(DrawingComponent *pDrawingComponent) {
        m_drawingComponent = pDrawingComponent;
    }
    
    void * Touch::GetSystemTouch() const {
        return m_systemTouch;
    }
    
    DrawingComponent * Touch::GetDrawingComponent() const {
        return m_drawingComponent;
    }
    
    Point Touch::GetWindowPosition() const {
        return m_windowPosition;
    }
    
    Point Touch::GetProjectionPosition() const {
        CSize windowSize = RenderingEngine::SharedInstance().GetWindowSize();
        float xOffset = m_windowPosition.x / windowSize.width;
        float yOffset = m_windowPosition.y / windowSize.height;
        
        Rect frontRect = RenderingEngine::SharedInstance().GetProjection().GetFrontRect();
        float xPosition = frontRect.x + frontRect.width * xOffset;
        float yPosition = frontRect.y + frontRect.height * yOffset;
        float zPosition = RenderingEngine::SharedInstance().GetProjection().GetDistance();
        return Point(xPosition, yPosition, zPosition);
    }
}