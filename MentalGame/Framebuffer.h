//
//  Framebuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 27.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include "Renderbuffer.h"
#include "Texture2D.h"
#include "TextureCubeMap.h"
#include "Color.h"



namespace Renderer {
    
    class Framebuffer {
    public:
        Framebuffer();
        Framebuffer(const Framebuffer &rFramebuffer) = delete;
        ~Framebuffer();
        
        virtual bool IsBoundRead() const;
        virtual bool IsBoundDraw() const;
        virtual void BindRead() const;
        virtual void BindDraw() const;
        virtual void Resolve() const;
        virtual void Discard() const;
        
        void Bind() const;
        void Clear() const;
        void Clear(GLbitfield mask) const;
        
        void AttachTexture2D(Texture2D *pTexture2D);
        void AttachTextureCubeMap(TextureCubeMap *pTextureCubeMap, TEXTURE_CUBE_MAP_SIDE side);
        void AttachColorRenderbuffer(Renderbuffer *pRenderbuffer);
        void AttachDepthRenderbuffer(Renderbuffer *pRenderbuffer);
        void AttachStencilRenderbuffer(Renderbuffer *pRenderbuffer);
        
        void DetachTexture2D();
        void DetachTextureCubeMap(TEXTURE_CUBE_MAP_SIDE side);
        void DetachColorRenderbuffer();
        void DetachDepthRenderbuffer();
        void DetachStencilRenderbuffer();
        
        Texture2D * GetTexture2D() const;
        TextureCubeMap * GetTextureCubeMap() const;
        Renderbuffer * GetColorRenderbuffer() const;
        Renderbuffer * GetDepthRenderbuffer() const;
        Renderbuffer * GetStencilRenderbuffer() const;
        
        void SetClearColor(const Color &rColor) const;
        void SetClearDepth(GLclampf depth) const;
        void SetClearStencil(GLint stencil) const;
        
        Color GetClearColor() const;
        GLclampf GetClearDepth() const;
        GLint GetClearStencil() const;
        
        // TODO: glCheckFramebufferStatus
        
    protected:
        GLuint GetName() const;
        
    private:
        void Generate();
        void Delete();
        
        bool IsBound() const;
        
        GLuint m_name;
        Texture2D *m_texture2D;
        TextureCubeMap *m_textureCubeMap;
        Renderbuffer *m_colorRenderbuffer;
        Renderbuffer *m_depthRenderbuffer;
        Renderbuffer *m_stencilRenderbuffer;
    };
}
