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
    
    TEXTURE Texture2D::GetTextureIdentifier() const {
        return TEXTURE_2D;
    }
    
    GET_PARAMETER Texture2D::GetTextureBindingIdentifier() const {
        return GET_PARAMETER_TEXTURE_BINDING_2D;
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