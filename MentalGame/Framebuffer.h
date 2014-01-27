//
//  Framebuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 27.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>



namespace Renderer {
    
    class Framebuffer {
    public:
        Framebuffer();
        Framebuffer(const Framebuffer &rFramebuffer) = delete;
        ~Framebuffer();
        
        void Bind() const;
        
    private:
        void Generate();
        void Delete();
        
        bool IsBound() const;
        
        GLuint m_name;
    };
}
