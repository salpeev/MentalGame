//
//  GLSLVertexBuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenglES/ES2/gl.h>
#include "GLSLVertexData.h"



namespace GLRenderer
{
    enum GLSL_BUFFER_USAGE
    {
        GLSL_BUFFER_USAGE_STREAM_DRAW,
        GLSL_BUFFER_USAGE_STATIC_DRAW,
        GLSL_BUFFER_USAGE_DYNAMIC_DRAW
    };
    
    
    
    class GLSLBuffer
    {
    public:
        GLSLBuffer();
        ~GLSLBuffer();
        
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual void LoadVertexData(GLSLVertexData *pVertexData, GLSL_BUFFER_USAGE usage = GLSL_BUFFER_USAGE_STATIC_DRAW) const = 0;
        
        GLenum OpenGLESUsageFromBufferUsage(GLSL_BUFFER_USAGE usage) const;
        
    protected:
        GLuint m_bufferHandle;
    };
}
