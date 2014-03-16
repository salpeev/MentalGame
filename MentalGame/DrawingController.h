//
//  DrawingController.h
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "CompositeDrawing.h"



namespace Renderer {
    
    class DrawingController {
    public:
        DrawingController();
        ~DrawingController();
        
        CompositeDrawing *GetDrawing() const;
        
    private:
        CompositeDrawing *m_drawing;
    };
}
