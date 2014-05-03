//
//  TextureInfo.h
//  MentalGame
//
//  Created by Sergey Alpeev on 03.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Constants.h"
#include "Size.h"



namespace Renderer {
    
    class TextureInfo {
    public:
        TextureInfo(void *bytes, CSize size, int bitsPerComponent, PIXEL_FORMAT pixelFormat);
        ~TextureInfo();
        
        const void *GetBytes() const;
        CSize GetSize() const;
        int GetBitsPerComponent() const;
        PIXEL_FORMAT GetPixelFormat() const;
        PIXEL_TYPE GetPixelType() const;
        
    private:
        void *m_bytes;
        CSize m_size;
        int m_bitsPerComponent;
        PIXEL_FORMAT m_pixelFormat;
    };
}
