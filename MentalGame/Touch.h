//
//  Touch.h
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"



namespace Renderer {
    
    class Touch {
    public:
        Touch(Point windowPosition);
        ~Touch();
        
        Point GetWindowPosition() const;
        Point GetProjectionPosition() const;
        
    private:
        Point m_windowPosition;
    };
}
