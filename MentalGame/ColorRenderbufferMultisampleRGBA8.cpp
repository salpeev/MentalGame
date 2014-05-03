//
//  ColorRenderbufferRGBA8.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorRenderbufferMultisampleRGBA8.h"
#include "Constants.h"
#include "Logger.h"
#include <OpenGLES/ES2/glext.h>



namespace Renderer {
    
    void ColorRenderbufferMultisampleRGBA8::CreateStorage(int width, int height) const {
        glRenderbufferStorageMultisampleAPPLE(FRAMEBUFFER_OBJECT_RENDERBUFFER, 4, GL_RGBA8_OES, width, height);
        CheckError();
    }
}
