//
//  StencilRenderbufferIndex8.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "StencilRenderbufferIndex8.h"
#include "GLConstants.h"
#include "Logger.h"



namespace Renderer {
    
    void StencilRenderbufferIndex8::CreateStorage(int width, int height) const {
        glRenderbufferStorage(FRAMEBUFFER_OBJECT_RENDERBUFFER, STENCIL_RENDERBUFFER_FORMAT_INDEX8, width, height);
        CheckError();
    }
}
