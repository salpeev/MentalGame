//
//  ColorRenderbufferRGB565.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Renderbuffer.h"



namespace Renderer {
    
    class ColorRenderbufferRGB565: public Renderbuffer {
    protected:
        void CreateStorage(int width, int height) const;
    };
}
