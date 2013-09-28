//
//  GLSLVertexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenglES/ES2/gl.h>



namespace GLRenderer
{
    class GLSLBuffer
    {
    public:
        GLSLBuffer();
        ~GLSLBuffer();
        
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        
    protected:
        GLuint m_bufferHandle;
    };
}
