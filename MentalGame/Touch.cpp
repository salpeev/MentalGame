//
//  Touch.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Touch.h"
#include "RenderingEngine.h"



namespace Renderer {
    
    Touch::Touch(Point windowPosition): m_windowPosition(windowPosition) {
        
    }
    
    Touch::~Touch() {
        
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
        return Point(xPosition, yPosition);
    }
}