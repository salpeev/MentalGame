//
//  Size.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Size.h"



namespace Renderer {
    
    Size::Size(): Size(0.0f, 0.0f) {
        
    }
    
    Size::Size(GLfloat width, GLfloat height): width(width), height(height) {
        
    }
}
