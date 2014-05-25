//
//  TextureCamera.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Camera.h"
#include "Renderbuffer.h"



namespace Renderer {
    
    class TextureCamera: public Camera {
    public:
        TextureCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthRenderbuffer, Renderbuffer *stencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType);
        TextureCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthStencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType);
        ~TextureCamera();
        
        Texture2D * RetrieveTexture();
        
        void PrepareForRecord();
        
    private:
        void GenerateTexture();
        
        PIXEL_FORMAT m_pixelFormat;
        PIXEL_TYPE m_pixelType;
        Texture2D *m_texture2D;
        Renderbuffer *m_depthRenderbuffer;
        Renderbuffer *m_stencilRenderbuffer;
    };
}
