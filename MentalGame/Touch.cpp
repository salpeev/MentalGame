//
//  Touch.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Touch.h"



namespace Renderer {
    
    Touch::Touch(Point windowPosition): m_windowPosition(windowPosition) {
        
    }
    
    Touch::~Touch() {
        
    }
    
    Point Touch::GetWindowPosition() const {
        return m_windowPosition;
    }
}