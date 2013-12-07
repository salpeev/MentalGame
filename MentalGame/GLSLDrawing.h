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
    class GLSLDrawingState;
    
    
    
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
        void UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        void UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        void UseVertexBuffer(GLSLVertexBuffer *pVertexBuffer);
        void UseRawVertexDataWithIndexBuffer(GLvoid *pVertexData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer);
        void UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLushort> &rIndices);
        void UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLubyte> &rIndices);
        void UseRawVertexData(GLvoid *pVertexData, GLsizei dataSize);
        
    protected:
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        virtual void InitializeAttributes(const map<string, GLSLAttribute *> *pAttributes, GLvoid *pData = NULL) const = 0;
        
    private:
        void GenerateProgram();
        
        void SetProgram(GLSLProgram *pProgram);
        GLSLProgram * GetProgram() const;
        
        void SetDrawingState(GLSLDrawingState *pDrawingState);
        
        GLSLProgram *m_program;
        GLSLDrawingState *m_drawingState;
//        GLSLVertexBuffer *m_vertexBuffer;
//        GLSLIndexBuffer *m_indexBuffer;
//        GLuint m_rawElementsCount;
    };
}
