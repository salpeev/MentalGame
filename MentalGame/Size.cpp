//
//  Size.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Size.h"



namespace Renderer {
    
    CSize::CSize(): CSize(0.0f, 0.0f) {
        
    }
    
    CSize::CSize(GLfloat width, GLfloat height): width(width), height(height) {
        
    }
}
