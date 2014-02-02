//
//  Rect.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 02.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Rect.h"



namespace Renderer {
    
    Rect::Rect(): Rect(0.0f, 0.0f, 0.0f, 0.0f) {
        
    }
    
    Rect::Rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height): x(x), y(y), width(width), height(height) {
        
    }
}