//
//  Texture.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenglES/ES2/gl.h>



namespace Renderer {
    class Texture {
    public:
        Texture();
        Texture(const Texture &rTexture) = delete;
        ~Texture();
        
        void Bind() const;
        bool IsBound() const;
        
    private:
        GLuint m_textureHandle;
    };
}
