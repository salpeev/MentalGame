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
    
    Touch::Touch(Point2 windowPosition, void *pSystemTouch): m_windowPosition(windowPosition), m_systemTouch(pSystemTouch) {
        
    }
    
    Touch::~Touch() {
        
    }
    
    void Touch::SetWindowPosition(const Point2 &rPosition) {
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
    
    Point2 Touch::GetWindowPosition() const {
        return m_windowPosition;
    }
    
    Point3 Touch::GetProjectionPosition() const {
        CSize windowSize = RenderingEngine::SharedInstance().GetMainCamera()->GetResolution();
        float xOffset = m_windowPosition.x / windowSize.width;
        float yOffset = m_windowPosition.y / windowSize.height;
        
        Rect frontRect = RenderingEngine::SharedInstance().GetMainCamera()->GetProjection().GetFrontRect();
        float xPosition = frontRect.origin.x + frontRect.size.width * xOffset;
        float yPosition = frontRect.origin.y + frontRect.size.height * yOffset;
        float zPosition = RenderingEngine::SharedInstance().GetMainCamera()->GetProjection().GetDistance();
        return Point3(xPosition, yPosition, zPosition);
    }
}