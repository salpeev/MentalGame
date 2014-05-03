//
//  ColorRenderbufferRGBA4.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorRenderbufferRGBA4.h"
#include "Constants.h"
#include "Logger.h"



namespace Renderer {
    
    void ColorRenderbufferRGBA4::CreateStorage(int width, int height) const {
        glRenderbufferStorage(FRAMEBUFFER_OBJECT_RENDERBUFFER, COLOR_RENDERBUFFER_FORMAT_RGBA4, width, height);
        CheckError();
    }
}
