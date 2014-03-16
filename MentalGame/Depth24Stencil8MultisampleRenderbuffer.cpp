//
//  DepthComponent24StencilIndex16Renderbuffer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Depth24Stencil8MultisampleRenderbuffer.h"
#include "GLConstants.h"
#include "Logger.h"
#include <OpenGLES/ES2/glext.h>



namespace Renderer {
    
    void Depth24Stencil8MultisampleRenderbuffer::CreateStorage(int width, int height) const {
        glRenderbufferStorageMultisampleAPPLE(FRAMEBUFFER_OBJECT_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8_OES, width, height);
        CheckError();
    }
}
