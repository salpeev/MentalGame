//
//  Framebuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 27.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>
#include "Renderbuffer.h"



namespace Renderer {
    
    class Framebuffer {
    public:
        Framebuffer();
        Framebuffer(const Framebuffer &rFramebuffer) = delete;
        ~Framebuffer();
        
        void Bind() const;
        
        void AttachColorRenderbuffer(Renderbuffer *pRenderbuffer);
        void AttachDepthRenderbuffer(Renderbuffer *pRenderbuffer);
        void AttachStencilRenderbuffer(Renderbuffer *pRenderbuffer);
        
        void DetachColorRenderbuffer();
        void DetachDepthRenderbuffer();
        void DetachStencilRenderbuffer();
        
        Renderbuffer * GetColorRenderbuffer() const;
        Renderbuffer * GetDepthRenderbuffer() const;
        Renderbuffer * GetStencilRenderbuffer() const;
        
    private:
        void Generate();
        void Delete();
        
        bool IsBound() const;
        
        GLuint m_name;
        Renderbuffer *m_colorRenderbuffer;
        Renderbuffer *m_depthRenderbuffer;
        Renderbuffer *m_stencilRenderbuffer;
    };
}
