//
//  TextureCamera.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 18.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TextureCamera.h"
#include "ColorRenderbufferMultisampleRGBA8.h"
#include "Depth24Stencil8MultisampleRenderbuffer.h"



namespace Renderer {
    
    TextureCamera::TextureCamera(float width, float height, const Projection &rProjection): Camera(width, height, rProjection) {
        m_framebuffer = new Framebuffer();
        m_depthStencilRenderbuffer = new Depth24Stencil8MultisampleRenderbuffer();
        
        TextureImage textureImage(CSize(640.0f, 1136.0f), BITS_PER_COMPONENT_4, PIXEL_FORMAT_RGBA);
        m_texture2D = new Texture2D();
        m_texture2D->SetTextureImage(&textureImage, 0);
    }
    
    TextureCamera::~TextureCamera() {
        delete m_framebuffer;
        delete m_texture2D;
        delete m_depthStencilRenderbuffer;
    }
    
    Framebuffer * TextureCamera::GetFramebuffer() const {
        return m_framebuffer;
    }
    
    Texture2D * TextureCamera::GetTexture2D() const {
        return m_texture2D;
    }
    
    Renderbuffer * TextureCamera::GetDepthRenderbuffer() const {
        return m_depthStencilRenderbuffer;
    }
    
    Renderbuffer * TextureCamera::GetStencilRenderbuffer() const {
        return m_depthStencilRenderbuffer;
    }
}