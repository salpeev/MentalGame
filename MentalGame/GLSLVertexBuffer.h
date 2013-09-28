//
//  GLSLVertexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLBuffer.h"



namespace GLRenderer
{
    class GLSLVertexBuffer : public GLSLBuffer
    {
    public:
        GLSLVertexBuffer();
        ~GLSLVertexBuffer();
        
        void Bind() const;
        void Unbind() const;
        void LoadVertexData(GLSLVertexData *pVertexData, GLSL_BUFFER_USAGE usage) const;
    };
}
