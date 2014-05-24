//
//  TextureImage.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 03.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TextureImage.h"
#include <stdlib.h>
#include <assert.h>



namespace Renderer {
    
    TextureImage::TextureImage(CSize size, PIXEL_FORMAT pixelFormat, PIXEL_TYPE pixelType, void *bytes): m_bytes(bytes), m_size(size), m_pixelFormat(pixelFormat), m_pixelType(pixelType) {
        
    }
    
    TextureImage::~TextureImage() {
        free(m_bytes);
    }
    
    const void * TextureImage::GetBytes() const {
        return m_bytes;
    }
    
    CSize TextureImage::GetSize() const {
        return m_size;
    }
    
    PIXEL_FORMAT TextureImage::GetPixelFormat() const {
        return m_pixelFormat;
    }
    
    PIXEL_TYPE TextureImage::GetPixelType() const {
        return m_pixelType;
    }
}