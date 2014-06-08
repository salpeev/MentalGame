//
//  Texture.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Texture.h"
#include "Logger.h"



namespace Renderer {
    
    Texture::Texture() {
        glGenTextures(1, &m_textureHandle);
        CheckError();
    }
    
    Texture::~Texture() {
        glDeleteTextures(1, &m_textureHandle);
        CheckError();
    }
    
    void Texture::Bind() const {
        if(!IsBound()) {
            glBindTexture(GetTextureIdentifier(), GetTextureHandle());
            CheckError();
        }
    }
    
    bool Texture::IsBound() const {
        GLint boundTextureHandle;
        glGetIntegerv(GetTextureBindingIdentifier(), &boundTextureHandle);
        CheckError();
        
        bool bound = (boundTextureHandle == GetTextureHandle());
        return bound;
    }
    
    void Texture::GenerateMipMap(MIPMAP_HINT hint) const {
        Bind();     // TODO: Is needed? Probably yes
        
        glHint(HINT_MIPMAP, hint);
        CheckError();
        
        glGenerateMipmap(GetTextureIdentifier());
        CheckError();
    }
    
    void Texture::SetMinFilter(TEX_MIN_FILTER minFilter) const {
        Bind();
        
        glTexParameteri(GetTextureIdentifier(), TEX_PARAMETER_MIN_FILTER, minFilter);
        CheckError();
    }
    
    void Texture::SetMagFilter(TEX_MAG_FILTER magFilter) const {
        Bind();
        
        glTexParameteri(GetTextureIdentifier(), TEX_PARAMETER_MAG_FILTER, magFilter);
        CheckError();
    }
    
    void Texture::SetWrapS(TEX_WRAP wrapS) const {
        Bind();
        
        glTexParameteri(GetTextureIdentifier(), TEX_PARAMETER_WRAP_S, wrapS);
        CheckError();
    }
    
    void Texture::SetWrapT(TEX_WRAP wrapT) const {
        Bind();
        
        glTexParameteri(GetTextureIdentifier(), TEX_PARAMETER_WRAP_T, wrapT);
        CheckError();
    }
    
    TEX_MIN_FILTER Texture::GetMinFilter() const {
        Bind();
        
        GLint minFilterParameter;
        glGetTexParameteriv(GetTextureIdentifier(), TEX_PARAMETER_MIN_FILTER, &minFilterParameter);
        CheckError();
        
        TEX_MIN_FILTER minFilter = (TEX_MIN_FILTER)minFilterParameter;
        return minFilter;
    }
    
    TEX_MAG_FILTER Texture::GetMagFilter() const {
        Bind();
        
        GLint magFilterParameter;
        glGetTexParameteriv(GetTextureIdentifier(), TEX_PARAMETER_MAG_FILTER, &magFilterParameter);
        CheckError();
        
        TEX_MAG_FILTER magFilter = (TEX_MAG_FILTER)magFilterParameter;
        return magFilter;
    }
    
    TEX_WRAP Texture::GetWrapS() const {
        Bind();
        
        GLint wrapSParameter;
        glGetTexParameteriv(GetTextureIdentifier(), TEX_PARAMETER_WRAP_S, &wrapSParameter);
        CheckError();
        
        TEX_WRAP wrapS = (TEX_WRAP)wrapSParameter;
        return wrapS;
    }
    
    TEX_WRAP Texture::GetWrapT() const {
        Bind();
        
        GLint wrapTParameter;
        glGetTexParameteriv(GetTextureIdentifier(), TEX_PARAMETER_WRAP_S, &wrapTParameter);
        CheckError();
        
        TEX_WRAP wrapT = (TEX_WRAP)wrapTParameter;
        return wrapT;
    }
    
    GLuint Texture::GetTextureHandle() const {
        return m_textureHandle;
    }
}