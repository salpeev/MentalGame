//
//  BufferCamera.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Camera.h"
#include "Renderbuffer.h"



namespace Renderer {
    
    class BufferCamera: public Camera {
    public:
        BufferCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *colorRenderbuffer, Renderbuffer *depthRenderbuffer, Renderbuffer *stencilRenderbuffer);
        BufferCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *colorRenderbuffer, Renderbuffer *depthStencilRenderbuffer);
        ~BufferCamera();
        
    private:
        Renderbuffer *m_colorRenderbuffer;
        Renderbuffer *m_depthRenderbuffer;
        Renderbuffer *m_stencilRenderbuffer;
    };
}
