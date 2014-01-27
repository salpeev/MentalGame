//
//  ColorRenderbuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Renderbuffer.h"



namespace Renderer {
    
    class ColorRenderbuffer {
    public:
        ColorRenderbuffer(int width, int height);
        ColorRenderbuffer(const ColorRenderbuffer &rColorRenderbuffer) = delete;
        ~ColorRenderbuffer();
        
    protected:
        
    };
}
