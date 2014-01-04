//
//  GLSLVertexData.h
//  MentalGame
//
//  Created by Sergey Alpeev on 04.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace GLRenderer
{
    class GLSLVertexArray
    {
    public:
        GLSLVertexArray(GLvoid *pData, GLsizei vertexSize, GLuint vertexesCount);
        GLSLVertexArray(const GLSLVertexArray &rVertexArray);
        ~GLSLVertexArray();
        
        GLvoid *GetData() const;
        GLsizei GetDataSize() const;
        GLsizei GetVertexSize() const;
        GLuint GetVertexesCount() const;
        
    private:
        GLvoid *m_data;
        GLsizei m_dataSize;
        GLsizei m_vertexSize;
        GLuint m_vertexesCount;
    };
}
