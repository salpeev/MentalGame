//
//  GLSLIndexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLBuffer.h"



namespace GLRenderer
{
    class GLSLIndexBuffer : public GLSLBuffer
    {
    public:
        GLSLIndexBuffer();
        ~GLSLIndexBuffer();
        
        void Bind() const;
        void Unbind() const;
    };
}

