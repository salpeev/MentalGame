//
//  Color.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Color.h"




namespace Renderer {
    
    Color::Color(): Color(0.0f, 0.0f, 0.0f, 0.0f) {
        
    }
    
    Color::Color(GLfloat r, GLfloat g, GLfloat b): Color(r, g, b, 1.0f) {
        
    }
    
    Color::Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a): r(r), g(g), b(b), a(a) {
        
    }
}