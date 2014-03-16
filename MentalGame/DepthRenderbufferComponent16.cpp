//
//  DepthRenderbufferComponent16.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DepthRenderbufferComponent16.h"
#include "GLConstants.h"
#include "Logger.h"



namespace Renderer {
    
    void DepthRenderbufferCompontent16::CreateStorage(int width, int height) const {
        glRenderbufferStorage(FRAMEBUFFER_OBJECT_RENDERBUFFER, DEPTH_RENDERBUFFER_FORMAT_COMPONENT16, width, height);
        CheckError();
    }
}
