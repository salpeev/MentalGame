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
        TextureImage(CSize size, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType, void *bytes = nullptr);
        ~TextureImage();
        
        const void *GetBytes() const;
        CSize GetSize() const;
        PIXEL_FORMAT GetPixelFormat() const;
        PIXEL_TYPE GetPixelType() const;
        
    private:
        void *m_bytes;
        CSize m_size;
        PIXEL_FORMAT m_pixelFormat;
        PIXEL_TYPE m_pixelType;
    };
}
