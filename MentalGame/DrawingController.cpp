//
//  DrawingController.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingController.h"



namespace Renderer {
    
    DrawingController::DrawingController() {
        m_drawing = new CompositeDrawing();
    }
    
    DrawingController::~DrawingController() {
        delete m_drawing;
    }
    
    CompositeDrawing * DrawingController::GetDrawing() const {
        return m_drawing;
    }
}