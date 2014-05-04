//
//  VertexData.h
//  MentalGame
//
//  Created by Sergey Alpeev on 04.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



namespace Renderer {
    
    class VertexArray {
    public:
        // TODO: Probably this class can have the same interface as GLSLBuffer
        VertexArray(GLvoid *pData, GLsizei vertexSize, GLuint verticesCount);
        VertexArray(const VertexArray &rVertexArray);
        ~VertexArray();
        
        GLvoid *GetData() const;
        GLsizei GetDataSize() const;
        GLsizei GetVertexSize() const;
        GLuint GetVerticesCount() const;
        
    private:
        GLvoid *m_data;
        GLsizei m_dataSize;
        GLsizei m_vertexSize;
        GLuint m_verticesCount;
    };
}
