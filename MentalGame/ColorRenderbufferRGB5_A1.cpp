//
//  ColorRenderbufferRGB5_A1.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorRenderbufferRGB5_A1.h"
#include "Constants.h"
#include "Logger.h"



namespace Renderer {
    
    void ColorRenderbufferRGB5_A1::CreateStorage(int width, int height) const {
        glRenderbufferStorage(FRAMEBUFFER_OBJECT_RENDERBUFFER, COLOR_RENDERBUFFER_FORMAT_RGB5_A1, width, height);
        CheckError();
    }
}