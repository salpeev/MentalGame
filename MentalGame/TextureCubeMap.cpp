//
//  TextureCubeMap.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 09.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TextureCubeMap.h"
#include "Logger.h"



namespace Renderer {
    
    void TextureCubeMap::Bind() const {
        if(!IsBound()) {
            glBindTexture(TEXTURE_CUBE_MAP, GetTextureHandle());
            CheckError();
        }
    }
    
    bool TextureCubeMap::IsBound() const {
        GLint boundTextureHandle;
        glGetIntegerv(GET_PARAMETER_TEXTURE_BINDING_2D, &boundTextureHandle);
        CheckError();
        
        bool bound = (boundTextureHandle == GetTextureHandle());
        return bound;
    }
    
    void TextureCubeMap::GenerateMipMap(MIPMAP_HINT hint) const {
        Bind();     // TODO: Is needed? Probably yes
        
        glHint(HINT_MIPMAP, hint);
        CheckError();
        
        glGenerateMipmap(TEXTURE_CUBE_MAP);
        CheckError();
    }
    
    void TextureCubeMap::SetTextureImage(TextureImage *textureImage, int level, TEXTURE_CUBE_MAP_SIDE side) const {
        Bind();
        
        PIXEL_FORMAT pixelFormat = textureImage->GetPixelFormat();
        GLsizei width = textureImage->GetSize().width;
        GLsizei height = textureImage->GetSize().height;
        PIXEL_TYPE pixelType = textureImage->GetPixelType();
        const GLvoid *pixels = textureImage->GetBytes();
        
        glTexImage2D(side, level, pixelFormat, width, height, 0, pixelFormat, pixelType, pixels);
        CheckError();
    }
}