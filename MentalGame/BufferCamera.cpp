//
//  BufferCamera.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "BufferCamera.h"



namespace Renderer {
    
    BufferCamera::BufferCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *colorRenderbuffer, Renderbuffer *depthRenderbuffer, Renderbuffer *stencilRenderbuffer): Camera(resolution, rProjection, pFramebuffer), m_colorRenderbuffer(colorRenderbuffer), m_depthRenderbuffer(depthRenderbuffer), m_stencilRenderbuffer(stencilRenderbuffer) {
        if (colorRenderbuffer) {
            colorRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachColorRenderbuffer(colorRenderbuffer);
        }
        
        if (depthRenderbuffer) {
            depthRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachDepthRenderbuffer(depthRenderbuffer);
        }
        
        if (stencilRenderbuffer) {
            stencilRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachStencilRenderbuffer(stencilRenderbuffer);
        }
    }
    
    BufferCamera::BufferCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *colorRenderbuffer, Renderbuffer *depthStencilRenderbuffer): Camera(resolution, rProjection, pFramebuffer), m_colorRenderbuffer(colorRenderbuffer), m_depthRenderbuffer(depthStencilRenderbuffer) {
        if (colorRenderbuffer) {
            colorRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachColorRenderbuffer(colorRenderbuffer);
        }
        
        if (depthStencilRenderbuffer) {
            depthStencilRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachDepthRenderbuffer(depthStencilRenderbuffer);
            GetFramebuffer()->AttachStencilRenderbuffer(depthStencilRenderbuffer);
        }
    }
    
    BufferCamera::~BufferCamera() {
        delete m_colorRenderbuffer;
        delete m_depthRenderbuffer;
        delete m_stencilRenderbuffer;
    }
}