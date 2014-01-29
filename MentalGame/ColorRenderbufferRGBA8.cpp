//
//  ColorRenderbufferRGBA8.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorRenderbufferRGBA8.h"
#include "GLConstants.h"
#include "GLLogger.h"
#include <OpenGLES/ES2/glext.h>



namespace Renderer {
    
    void ColorRenderbufferRGBA8::CreateStorage(int width, int height) const {
        glRenderbufferStorage(FRAMEBUFFER_OBJECT_RENDERBUFFER, GL_RGBA8_OES, width, height);
        CheckError();
    }
}
