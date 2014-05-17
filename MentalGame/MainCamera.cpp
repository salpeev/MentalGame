//
//  MainCamera.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 17.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "MainCamera.h"
#include "MultisampleFramebuffer.h"
#include "ColorRenderbufferMultisampleRGBA8.h"
#include "Depth24Stencil8MultisampleRenderbuffer.h"



namespace Renderer {
    MainCamera::MainCamera(float width, float height): Camera(width, height) {
        m_framebuffer = new MultisampleFramebuffer();
        m_colorRenderbuffer = new ColorRenderbufferMultisampleRGBA8();
        m_depthStencilRenderbuffer = new Depth24Stencil8MultisampleRenderbuffer();
    }
    
    MainCamera::~MainCamera() {
        delete m_framebuffer;
        delete m_colorRenderbuffer;
        delete m_depthStencilRenderbuffer;
    }
    
    Framebuffer * MainCamera::GetFramebuffer() const {
        return m_framebuffer;
    }
    
    Renderbuffer * MainCamera::GetColorRenderbuffer() const {
        return m_colorRenderbuffer;
    }
    
    Renderbuffer * MainCamera::GetDepthRenderbuffer() const {
        return m_depthStencilRenderbuffer;
    }
    
    Renderbuffer * MainCamera::GetStencilRenderbuffer() const {
        return m_depthStencilRenderbuffer;
    }
}