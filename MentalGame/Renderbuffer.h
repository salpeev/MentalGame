//
//  Renderbuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 27.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace Renderer {
    
    class Renderbuffer {
    public:
        Renderbuffer();
        Renderbuffer(const Renderbuffer &rRenderbuffer) = delete;
        virtual ~Renderbuffer();
        
        void EstablishStorage(int width, int height);
        void Bind() const;
        
        GLuint GetName() const;
        
    protected:
        virtual void CreateStorage(int width, int height) const;
        
    private:
        void Generate();
        void Delete();
        
        bool IsBound() const;
        
        GLuint m_name;
        bool m_storageEstablished;
    };
}
