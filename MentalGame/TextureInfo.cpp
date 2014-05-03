//
//  TextureInfo.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 03.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TextureInfo.h"
#include <stdlib.h>
#include <assert.h>



namespace Renderer {
    
    TextureInfo::TextureInfo (void *bytes, CSize size, int bitsPerComponent, PIXEL_FORMAT pixelFormat): m_bytes(bytes), m_size(size), m_bitsPerComponent(bitsPerComponent), m_pixelFormat(pixelFormat) {
        
    }
    
    TextureInfo::~TextureInfo() {
        free(m_bytes);
    }
    
    const void * TextureInfo::GetBytes() const {
        return m_bytes;
    }
    
    CSize TextureInfo::GetSize() const {
        return m_size;
    }
    
    int TextureInfo::GetBitsPerComponent() const {
        return m_bitsPerComponent;
    }
    
    PIXEL_FORMAT TextureInfo::GetPixelFormat() const {
        return m_pixelFormat;
    }
    
    PIXEL_TYPE TextureInfo::GetPixelType() const {
        PIXEL_TYPE pixelType = PIXEL_TYPE_NONE;
        
        
        switch (GetBitsPerComponent()) {
            case 4: {
                if (GetPixelFormat() == GL_RGBA) {
                    pixelType = PIXEL_TYPE_USHORT_4_4_4_4;
                    break;
                }
            }
            case 8: {
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