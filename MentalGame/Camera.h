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
#include "Projection.h"



namespace Renderer {
    class Camera {
    public:
        Camera(float width, float height, const Projection &rProjection);
        virtual ~Camera();
        
        void Initialize() const;
        void Enable() const;
        
        CSize GetResolution() const;
        
        void SetViewport(const Rect &rViewport) const;
        Rect GetViewport() const;
        
        void SetProjection(const Projection &rProjection);
        const Projection & GetProjection() const;
        
        virtual Framebuffer * GetFramebuffer() const = 0;
        virtual Renderbuffer * GetColorRenderbuffer() const = 0;
        virtual Renderbuffer * GetDepthRenderbuffer() const = 0;
        virtual Renderbuffer * GetStencilRenderbuffer() const = 0;
        
    private:
        CSize m_resolution;
        Projection m_projection;
    };
}
