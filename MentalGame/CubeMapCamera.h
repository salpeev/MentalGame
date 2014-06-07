//
//  CubeMapCamera.h
//  MentalGame
//
//  Created by Sergey Alpeev on 25.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Camera.h"
#include "Renderbuffer.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class CubeMapCamera: public Camera {
    public:
        CubeMapCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthRenderbuffer, Renderbuffer *stencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType);
        CubeMapCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthStencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType);
        ~CubeMapCamera();
        
        void SetPosition(const Point3 &rPosition);
        
        TextureCubeMap * GetTextureCubeMap() const;
        TextureCubeMap * RetrieveCubeMap();
        
        void Record();
        void PrepareForRecord();
        
    private:
        void GenerateCubeMap();
        
        PIXEL_FORMAT m_pixelFormat;
        PIXEL_TYPE m_pixelType;
        TextureCubeMap *m_cubeMap;
        Renderbuffer *m_depthRenderbuffer;
        Renderbuffer *m_stencilRenderbuffer;
        
        Point3 m_position;
        vector<Matrix4> m_projections;
    };
}
