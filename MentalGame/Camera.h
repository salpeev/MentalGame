//
//  Camera.h
//  MentalGame
//
//  Created by Sergey Alpeev on 14.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Size.h"
#include "Rect.h"
#include "Framebuffer.h"
#include "Renderbuffer.h"



namespace Renderer {
    class Camera {
    public:
        Camera(float width, float height);
        virtual ~Camera();
        
        void Initialize() const;
        
        void SetViewport(const Rect &rViewport) const;
        Rect GetViewport() const;
        
        virtual Framebuffer * GetFramebuffer() const = 0;
        virtual Renderbuffer * GetColorRenderbuffer() const = 0;
        virtual Renderbuffer * GetDepthRenderbuffer() const = 0;
        virtual Renderbuffer * GetStencilRenderbuffer() const = 0;
        
    private:
        CSize m_resolution;
    };
}
