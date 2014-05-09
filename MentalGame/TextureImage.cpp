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
    
    TextureImage::TextureImage(CSize size, BITS_PER_COMPONENT bitsPerComponent, PIXEL_FORMAT pixelFormat, void *bytes): m_bytes(bytes), m_size(size), m_bitsPerComponent(bitsPerComponent), m_pixelFormat(pixelFormat) {
        
    }
    
    TextureImage::TextureImage(CSize size, BITS_PER_COMPONENT bitsPerComponent, PIXEL_FORMAT pixelFormat): TextureImage(size, bitsPerComponent, pixelFormat, nullptr) {
        
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
    
    BITS_PER_COMPONENT TextureImage::GetBitsPerComponent() const {
        return m_bitsPerComponent;
    }
    
    PIXEL_FORMAT TextureImage::GetPixelFormat() const {
        return m_pixelFormat;
    }
    
    PIXEL_TYPE TextureImage::GetPixelType() const {
        PIXEL_TYPE pixelType = PIXEL_TYPE_NONE;
        
        
        switch (GetBitsPerComponent()) {
            case BITS_PER_COMPONENT_4: {
                if (GetPixelFormat() == GL_RGBA) {
                    pixelType = PIXEL_TYPE_USHORT_4_4_4_4;
                    break;
                }
            }
            case BITS_PER_COMPONENT_8: {
                pixelType = PIXEL_TYPE_UBYTE;
                break;
            }
            default: {
                assert(!"Unsupported format");
            }
        }
        
        return pixelType;
    }
}