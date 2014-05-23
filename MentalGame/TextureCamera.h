//
//  TextureCamera.h
//  MentalGame
//
//  Created by Sergey Alpeev on 18.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Camera.h"



namespace Renderer {
    
    class DepthRenderbufferCompontent16;
    
    
    
    class TextureCamera: public Camera {
    public:
        TextureCamera(float width, float height, const Projection &rProjection);
        ~TextureCamera();
        
        Framebuffer * GetFramebuffer() const;
        Texture2D * GetTexture2D() const;
        Renderbuffer * GetDepthRenderbuffer() const;
        Renderbuffer * GetStencilRenderbuffer() const;
        
    private:
        Framebuffer *m_framebuffer;
        Texture2D *m_texture2D;
        DepthRenderbufferCompontent16 *m_depthRenderbuffer;
    };
}