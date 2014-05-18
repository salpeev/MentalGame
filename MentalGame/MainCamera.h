//
//  MainCamera.h
//  MentalGame
//
//  Created by Sergey Alpeev on 17.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Camera.h"



namespace Renderer {
    
    class MultisampleFramebuffer;
    class ColorRenderbufferMultisampleRGBA8;
    class Depth24Stencil8MultisampleRenderbuffer;
    
    
    
    class MainCamera: public Camera {
    public:
        MainCamera(float width, float height, const Projection &rProjection);
        ~MainCamera();
        
        Framebuffer * GetFramebuffer() const;
        Renderbuffer * GetColorRenderbuffer() const;
        Renderbuffer * GetDepthRenderbuffer() const;
        Renderbuffer * GetStencilRenderbuffer() const;
        
    private:
        MultisampleFramebuffer *m_framebuffer;
        ColorRenderbufferMultisampleRGBA8 *m_colorRenderbuffer;
        Depth24Stencil8MultisampleRenderbuffer *m_depthStencilRenderbuffer;
    };
}