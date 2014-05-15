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



namespace Renderer {
    class Camera {
    public:
        Camera();
        ~Camera();
        
        void SetResolution(const CSize &rSize);
        void SetViewport(const Rect &rViewport) const;
        
        CSize GetResolution() const;
        Rect GetViewport() const;
        
    private:
        CSize m_resolution;
    };
}
