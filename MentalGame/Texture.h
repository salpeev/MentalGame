//
//  Texture.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Constants.h"
#include "TextureImage.h"
#include <OpenglES/ES2/gl.h>



namespace Renderer {
    
    // TODO: Hint, generate mipmap
    class Texture {
    public:
        Texture();
        Texture(const Texture &rTexture) = delete;
        ~Texture();
        
        virtual void Bind() const = 0;
        virtual bool IsBound() const = 0;
        virtual void GenerateMipMap(MIPMAP_HINT hint) const = 0;
        
        void SetMinFilter(TEX_MIN_FILTER minFilter) const;
        void SetMagFilter(TEX_MAG_FILTER magFilter) const;
        void SetWrapS(TEX_WRAP wrapS) const;
        void SetWrapT(TEX_WRAP wrapT) const;
        
        TEX_MIN_FILTER GetMinFilter() const;
        TEX_MAG_FILTER GetMagFilter() const;
        TEX_WRAP GetWrapS() const;
        TEX_WRAP GetWrapT() const;
        
        void GenerateMipMap() const;
        
        GLuint GetTextureHandle() const;
        
    private:
        GLuint m_textureHandle;
    };
}
