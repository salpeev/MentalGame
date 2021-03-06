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
#include "Quaternion.h"
#include <iostream>

using namespace std;



namespace Renderer {
    class Camera {
    public:
        Camera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer);
        virtual ~Camera();
        
        void SetProjection(const Projection &rProjection);
        void SetDrawingCallback(function<void (const Matrix4 &rProjectionMatrix)> drawingCallback);
        
        const CSize & GetResolution() const;
        const Projection & GetProjection() const;
        const Matrix4 & GetViewMatrix() const;
        Matrix4 GetViewProjectionMatrix() const;
        Framebuffer * GetFramebuffer() const;
        
        // TODO: Create three separate methods
        virtual void SetLookAt(const Point3 &rPosition, const Point3 &rTarget, const Vector3 &rUp);
        virtual void Record();
        virtual void PrepareForRecord();
        
    private:
        CSize m_resolution;
        Matrix4 m_viewMatrix;
        Projection m_projection;
        Framebuffer *m_framebuffer;
        
        function<void (const Matrix4 &rProjectionMatrix)> *m_drawingCallback;
    };
}
