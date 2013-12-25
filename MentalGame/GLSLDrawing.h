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
#include "GLConstants.h"
#include "GLSLDrawingState.h"

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    class GLSLAttribute;
    class GLSLUniform;
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    
    
    
    class GLSLDrawing: public GLSLDrawingStateDelegate
    {
    public:
        GLSLDrawing();
        GLSLDrawing(const GLSLDrawing &rDrawing) = delete;
        virtual ~GLSLDrawing();
        
        void Draw() const;
        
        void SetRenderMode(GLSL_RENDER_MODE renderMode);
        
        void SetStartDrawIndex(GLint startDrawIndex);
        GLint GetStartDrawIndex() const;
        
        void SetDrawElementsCount(GLsizei drawCount);
        GLsizei GetDrawElementsCount() const;
        
        void ResetStartDrawIndex();
        void ResetDrawElementsCount();
        void ResetStartDrawIndexAndDrawElementsCount();
        
        void UseVertexBufferWithIndexBuffer(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        void UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        void UseVertexBufferWithIndices(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        void UseVertexBuffer(GLSLVertexBuffer *pVertexBuffer);
        void UseRawVertexDataWithIndexBuffer(GLvoid *pVertexData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer);
        void UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLushort> &rIndices);
        void UseRawVertexDataWithRawIndexData(GLvoid *pVertexData, GLsizei dataSize, vector<GLubyte> &rIndices);
        void UseRawVertexData(GLvoid *pVertexData, GLsizei elementSize, GLuint elementsCount);
        
        // GLSLDrawingStateDelegate
        void PerformAttributesInitialization(GLvoid *pData = NULL) const;
        
    protected:
        GLSLAttribute * GetAttributeByName(string attributeName) const;
        GLSLUniform * GetUniformByName(string uniformName) const;
        
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        virtual void InitializeAttributes(GLvoid *pData = NULL) const = 0;
        virtual void InitializeUniforms() const;
        
    private:
        void GenerateProgram();
        void GenerateProgramIfNeeded();
        
        void SetProgram(GLSLProgram *pProgram);
        GLSLProgram * GetProgram() const;
        
        void SetDrawingState(GLSLDrawingState *pDrawingState);
        
        GLSLProgram *m_program;
        GLSLDrawingState *m_drawingState;
    };
}
