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
        
        // TODO: Clear buffers here (glClear)
        
        // TODO: Check this:
//        glBindFramebuffer(GL_FRAMEBUFFER, sampleFramebuffer);
//        glViewport(0, 0, framebufferWidth, framebufferHeight);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // TODO: glCheckFramebufferStatus
        
    protected:
        GLuint GetName() const;
        
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
