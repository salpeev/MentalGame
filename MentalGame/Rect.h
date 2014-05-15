//
//  Rect.h
//  MentalGame
//
//  Created by Sergey Alpeev on 02.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"
#include "Size.h"



namespace Renderer {
    
    class Rect {
    public:
        Rect();
        Rect(float x, float y, float width, float height);
        
        Point2 origin;
        CSize size;
    };
}
