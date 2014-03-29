//
//  FullscreenDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingComposite.h"



namespace Renderer {
    
    class FullscreenDrawing: public DrawingComposite {
    public:
        bool PointInside(const Point &rPoint) const;
    };
}
