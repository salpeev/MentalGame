//
//  Texture2D.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Texture2D.h"
#include "Logger.h"



namespace Renderer {
    
    void Texture2D::Bind() const {
        if(!IsBound()) {
            glBindTexture(TEXTURE_2D, GetTextureHandle());
            CheckError();
        }
    }
    
    bool Texture2D::IsBound() const {
        GLint boundTextureHandle;
        glGetIntegerv(GET_PARAMETER_TEXTURE_BINDING_2D, &boundTextureHandle);
        CheckError();
        
        bool bound = (boundTextureHandle == GetTextureHandle());
        return bound;
    }
    
    void Texture2D::GenerateMipMap(MIPMAP_HINT hint) const {
        Bind();     // TODO: Is needed? Probably yes
        
        glHint(HINT_MIPMAP, hint);
        CheckError();
        
        glGenerateMipmap(TEXTURE_2D);
        CheckError();
    }
    
    void Texture2D::SetTextureImage(TextureImage *textureImage, int level) const {
        Bind();
        
        PIXEL_FORMAT pixelFormat = textureImage->GetPixelFormat();
        GLsizei width = textureImage->GetSize().width;
        GLsizei height = textureImage->GetSize().height;
        PIXEL_TYPE pixelType = textureImage->GetPixelType();
        const GLvoid *pixels = textureImage->GetBytes();
        
        glTexImage2D(TEXTURE_2D, level, pixelFormat, width, height, 0, pixelFormat, pixelType, pixels);
        CheckError();
    }
}