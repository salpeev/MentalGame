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
    
    TEXTURE TextureCubeMap::GetTextureIdentifier() const {
        return TEXTURE_CUBE_MAP;
    }
    
    GET_PARAMETER TextureCubeMap::GetTextureBindingIdentifier() const {
        return GET_PARAMETER_TEXTURE_BINDING_CUBE_MAP;
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