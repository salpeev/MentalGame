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
#include "Projection.h"



namespace Renderer {
    class Camera {
    public:
        Camera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer);
        virtual ~Camera();
        
        void Enable();
        void SetProjection(const Projection &rProjection);
        
        const CSize & GetResolution() const;
        const Projection & GetProjection() const;
        Framebuffer * GetFramebuffer() const;
        
        virtual void PrepareForEnable();
        
    private:
        CSize m_resolution;
        Projection m_projection;
        Framebuffer *m_framebuffer;
    };
}
