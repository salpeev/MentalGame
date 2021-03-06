//
//  CubeMapCamera.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "CubeMapCamera.h"
#include "RenderingEngine.h"
#include "Logger.h"



namespace Renderer {
    
    CubeMapCamera::CubeMapCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthRenderbuffer, Renderbuffer *stencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType): Camera(resolution, rProjection, pFramebuffer), m_depthRenderbuffer(depthRenderbuffer), m_stencilRenderbuffer(stencilRenderbuffer), m_pixelFormat(pixelFormat), m_pixelType(pixelType) {
        m_projections.resize(TEXTURE_CUBE_MAP_SIDE_COUNT);
        SetLookAt(Point3(), Point3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f));
        
        GenerateCubeMap();
        
        if (depthRenderbuffer) {
            depthRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachDepthRenderbuffer(depthRenderbuffer);
        }
        
        if (stencilRenderbuffer) {
            stencilRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachStencilRenderbuffer(stencilRenderbuffer);
        }
    }
    
    CubeMapCamera::CubeMapCamera(CSize resolution, const Projection &rProjection, Framebuffer *pFramebuffer, Renderbuffer *depthStencilRenderbuffer, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType): Camera(resolution, rProjection, pFramebuffer), m_depthRenderbuffer(depthStencilRenderbuffer), m_stencilRenderbuffer(nullptr), m_pixelFormat(pixelFormat), m_pixelType(pixelType) {
        m_projections.resize(TEXTURE_CUBE_MAP_SIDE_COUNT);
        SetLookAt(Point3(), Point3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f));
        
        GenerateCubeMap();
        
        if (depthStencilRenderbuffer) {
            depthStencilRenderbuffer->EstablishStorage(resolution.width, resolution.height);
            GetFramebuffer()->AttachDepthRenderbuffer(depthStencilRenderbuffer);
            GetFramebuffer()->AttachStencilRenderbuffer(depthStencilRenderbuffer);
        }
    }
    
    CubeMapCamera::~CubeMapCamera() {
        delete m_cubeMap;
        delete m_depthRenderbuffer;
        delete m_stencilRenderbuffer;
    }
    
    TextureCubeMap * CubeMapCamera::GetTextureCubeMap() const {
        return m_cubeMap;
    }
    
    TextureCubeMap * CubeMapCamera::RetrieveCubeMap() {
        GetFramebuffer()->DetachTexture2D();
        TextureCubeMap *cubeMap = m_cubeMap;
        m_cubeMap = nullptr;
        return cubeMap;
    }
    
    void CubeMapCamera::SetLookAt(const Point3 &rPosition, const Point3 &rTarget, const Vector3 &rUp) {
        Camera::SetLookAt(rPosition, rTarget, rUp);
        
        Matrix4 cameraMatrix = GetViewMatrix();
        
        const Vector4 &rX = GetProjection().GetProjectionMatrix().x;
        const Vector4 &rY = GetProjection().GetProjectionMatrix().y;
        const Vector4 &rZ = GetProjection().GetProjectionMatrix().z;
        const Vector4 &rW = GetProjection().GetProjectionMatrix().w;
        
        m_projections[0] = cameraMatrix * Matrix4(-rZ, -rY, -rX, rW);
        m_projections[1] = cameraMatrix * Matrix4( rZ, -rY,  rX, rW);
        m_projections[2] = cameraMatrix * Matrix4( rX, -rZ,  rY, rW);
        m_projections[3] = cameraMatrix * Matrix4( rX,  rZ, -rY, rW);
        m_projections[4] = cameraMatrix * Matrix4( rX, -rY, -rZ, rW);
        m_projections[5] = cameraMatrix * Matrix4(-rX, -rY,  rZ, rW);
    }
    
    void CubeMapCamera::Record() {
        PrepareForRecord();
        
        GetFramebuffer()->Bind();
        
        for (int sideIndex = 0; sideIndex < TEXTURE_CUBE_MAP_SIDE_COUNT; sideIndex++) {
            GetFramebuffer()->AttachTextureCubeMap(m_cubeMap, TEXTURE_CUBE_MAP_SIDE(TEXTURE_CUBE_MAP_SIDE_POSITIVE_X + sideIndex));
            GetFramebuffer()->Clear();
            RenderingEngine::SharedInstance().RenderScene(m_projections[sideIndex]);
        }
    }
    
    void CubeMapCamera::PrepareForRecord() {
        if (!m_cubeMap) {
            GenerateCubeMap();
        }
    }
    
    void CubeMapCamera::GenerateCubeMap() {
        CSize resolution = GetResolution();
        m_cubeMap = new TextureCubeMap();
        
        for (int sideIndex = 0; sideIndex < TEXTURE_CUBE_MAP_SIDE_COUNT; sideIndex++) {
            TextureImage textureImage(resolution, m_pixelFormat, m_pixelType);
            m_cubeMap->SetTextureImage(&textureImage, 0, TEXTURE_CUBE_MAP_SIDE(TEXTURE_CUBE_MAP_SIDE_POSITIVE_X + sideIndex));
//            GetFramebuffer()->AttachTextureCubeMap(m_cubeMap, TEXTURE_CUBE_MAP_SIDE(TEXTURE_CUBE_MAP_SIDE_POSITIVE_X + sideIndex));
        }
        
        GetFramebuffer()->AttachTextureCubeMap(m_cubeMap, TEXTURE_CUBE_MAP_SIDE_POSITIVE_X);
    }
}