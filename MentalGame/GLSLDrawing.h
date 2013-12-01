//
//  GLSLDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <string>
#include <map>
#include <vector>
#include <OpenGLES/ES2/gl.h>

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    class GLSLAttribute;
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    
    
    
    class GLSLDrawing
    {
    public:
        GLSLDrawing();
        GLSLDrawing(const GLSLDrawing &rDrawing) = delete;
        virtual ~GLSLDrawing();
        
        void Initialize();
        void Draw() const;
        
#warning Check and refactor all this methods
        void UseVertexBufferWithIndexBuffer(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        void UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> *pIndices);
        void UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> *pIndices);
        void UseVertexBuffer(GLSLVertexBuffer *pVertexBuffer);
//        void UseRawVertexDataWithIndexBuffer(GLvoid *pVertexData, GLSLIndexBuffer *pIndexBuffer);
//        void UseRawVertexDataWithRawIndexData(GLushort);
//        void UseRawVertexDataWithRawIndexData(GLubyte);
        void UseRawVertexData(GLvoid *pVertexData, GLuint elementsCount);
        
    protected:
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        virtual void InitializeAttributes(const map<string, GLSLAttribute *> *pAttributes, GLvoid *pData = NULL) const = 0;
        
    private:
        void GenerateProgram();
        
        void SetProgram(GLSLProgram *pProgram);
        GLSLProgram * GetProgram() const;
        
        GLSLProgram *m_program;
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
        GLuint m_rawElementsCount;
    };
}
