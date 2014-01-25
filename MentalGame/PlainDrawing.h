//
//  PlainDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Drawing.h"



namespace Renderer {
    
    class PlainDrawing: public Drawing {
    public:
        PlainDrawing();
        ~PlainDrawing();
        
        void Draw() const;
    };
}
