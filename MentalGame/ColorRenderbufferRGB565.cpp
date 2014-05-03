//
//  ColorRenderbufferRGB565.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorRenderbufferRGB565.h"
#include "Constants.h"
#include "Logger.h"



namespace Renderer {
    
    void ColorRenderbufferRGB565::CreateStorage(int width, int height) const {
        glRenderbufferStorage(FRAMEBUFFER_OBJECT_RENDERBUFFER, COLOR_RENDERBUFFER_FORMAT_RGB565, width, height);
        CheckError();
    }
}