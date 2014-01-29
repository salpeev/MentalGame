//
//  ColorRenderbufferRGB5_A1.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorRenderbuffer.h"



namespace Renderer {
    
    class ColorRenderbufferRGB5_A1: public ColorRenderbuffer {
    protected:
        void CreateStorage(int width, int height) const;
    };
}
