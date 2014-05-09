//
//  TextureImage.h
//  MentalGame
//
//  Created by Sergey Alpeev on 03.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Constants.h"
#include "Size.h"



namespace Renderer {
    
    class TextureImage {
    public:
        TextureImage(CSize size, BITS_PER_COMPONENT bitsPerComponent, PIXEL_FORMAT pixelFormat, void *bytes);
        TextureImage(CSize size, BITS_PER_COMPONENT bitsPerComponent, PIXEL_FORMAT pixelFormat);
        ~TextureImage();
        
        const void *GetBytes() const;
        CSize GetSize() const;
        BITS_PER_COMPONENT GetBitsPerComponent() const;
        PIXEL_FORMAT GetPixelFormat() const;
        PIXEL_TYPE GetPixelType() const;
        
    private:
        void *m_bytes;
        CSize m_size;
        BITS_PER_COMPONENT m_bitsPerComponent;
        PIXEL_FORMAT m_pixelFormat;
    };
}
