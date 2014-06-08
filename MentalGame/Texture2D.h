//
//  Texture2D.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Texture.h"



namespace Renderer {
    
    class Texture2D: public Texture {
    public:
        TEXTURE GetTextureIdentifier() const;
        GET_PARAMETER GetTextureBindingIdentifier() const;
        
        void SetTextureImage(TextureImage *textureImage, int level) const;
    };
}
