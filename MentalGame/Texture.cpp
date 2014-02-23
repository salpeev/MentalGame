//
//  Texture.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Texture.h"
#include "GLLogger.h"



namespace Renderer {
    
    Texture::Texture() {
        glGenTextures(1, &m_textureHandle);
        CheckError();
    }
    
    Texture::~Texture() {
        glDeleteTextures(1, &m_textureHandle);
        CheckError();
    }
    
    void Texture::Bind() const {
        
    }
    
    bool Texture::IsBound() const {
        return false;
    }
}