//
//  TextureCamera.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TextureCamera.h"



namespace Renderer {
    
    TextureCamera::TextureCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthRenderbuffer, Renderbuffer *stencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType): Camera(resolution, rProjection, pFramebuffer), m_depthRenderbuffer(depthRenderbuffer), m_stencilRenderbuffer(stencilRenderbuffer), m_pixelFormat(pixelFormat), m_pixelType(pixelType) {
        GenerateTexture();
        
        if (depthRenderbuffer) {
            depthRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachDepthRenderbuffer(depthRenderbuffer);
        }
        
        if (stencilRenderbuffer) {
            stencilRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachStencilRenderbuffer(stencilRenderbuffer);
        }
    }
    
    TextureCamera::TextureCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthStencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType): Camera(resolution, rProjection, pFramebuffer), m_depthRenderbuffer(depthStencilRenderbuffer), m_stencilRenderbuffer(nullptr), m_pixelFormat(pixelFormat), m_pixelType(pixelType) {
        GenerateTexture();
        
        if (depthStencilRenderbuffer) {
            depthStencilRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachDepthRenderbuffer(depthStencilRenderbuffer);
            GetFramebuffer()->AttachStencilRenderbuffer(depthStencilRenderbuffer);
        }
    }
    
    TextureCamera::~TextureCamera() {
        delete m_texture2D;
        delete m_depthRenderbuffer;
        delete m_stencilRenderbuffer;
    }
    
    Texture2D * TextureCamera::RetrieveTexture() {
        GetFramebuffer()->DetachTexture2D();
        Texture2D *texture2D = m_texture2D;
        m_texture2D = nullptr;
        return texture2D;
    }
    
    void TextureCamera::PrepareForRecord() {
        if (!m_texture2D) {
            GenerateTexture();
        }
    }
    
    void TextureCamera::GenerateTexture() {
        CSize resolution = GetResolution();
        TextureImage textureImage(resolution, m_pixelFormat, m_pixelType);
        m_texture2D = new Texture2D();
        m_texture2D->SetTextureImage(&textureImage, 0);
        
        GetFramebuffer()->AttachTexture2D(m_texture2D);
    }
}