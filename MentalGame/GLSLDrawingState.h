//
//  GLSLDrawingState.h
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include <vector>
#include "GLConstants.h"
#include "GLSLVertexArray.h"
#include "GLSLProgramInitializer.h"

using namespace std;



namespace GLRenderer
{
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    
    
    
#pragma mark - GLSLDrawingState
    
    class GLSLDrawingState
    {
    public:
        GLSLDrawingState(GLSLProgramInitializer *pProgramInitializer);
        GLSLDrawingState(const GLSLDrawingState &rDrawingState) = delete;
        virtual ~GLSLDrawingState();
        
        void SetRenderMode(GLSL_RENDER_MODE renderMode);
        void SetStartDrawIndex(GLint startDrawIndex);
        void SetDrawElementsCount(GLsizei drawElementsCount);
        
        GLSL_RENDER_MODE GetRenderMode() const;
        GLint GetStartDrawIndex() const;
        GLsizei GetDrawElementsCount() const;
        GLSLProgramInitializer * GetProgramInitializer() const;
        
        void ResetStartDrawIndex();
        void ResetDrawCount();
        void ResetStartDrawIndexAndDrawElementsCount();
        
        virtual GLsizei GetVerticesCount() const = 0;
        virtual void PerformDrawing() const = 0;
        
    private:
        GLSLProgramInitializer *m_programInitializer;
        GLSL_RENDER_MODE m_renderMode;
        GLint m_startDrawIndex;
        GLsizei m_drawElementsCount;
    };
    
    
    
#pragma mark - GLSLVertexBufferIndexBufferState
    
    class GLSLVertexBufferIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferIndexBufferState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesState
    
    class GLSLVertexBufferShortIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferShortIndicesState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        ~GLSLVertexBufferShortIndicesState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesState
    
    class GLSLVertexBufferByteIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferByteIndicesState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        ~GLSLVertexBufferByteIndicesState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferState
    
    class GLSLVertexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer);
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferState
    
    class GLSLVertexArrayIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexArrayIndexBufferState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer);
        ~GLSLVertexArrayIndexBufferState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesState
    
    class GLSLVertexArrayShortIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexArrayShortIndicesState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices);
        ~GLSLVertexArrayShortIndicesState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesState
    
    class GLSLVertexArrayByteIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexArrayByteIndicesState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices);
        ~GLSLVertexArrayByteIndicesState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayState
    
    class GLSLVertexArrayState: public GLSLDrawingState
    {
    public:
        GLSLVertexArrayState(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray);
        ~GLSLVertexArrayState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
    };
    
    
    
#pragma mark - GLSLVertexArraysIndexBufferState
    
    class GLSLVertexArraysIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexArraysIndexBufferState(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer);
        ~GLSLVertexArraysIndexBufferState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArraysShortIndicesState
    
    class GLSLVertexArraysShortIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexArraysShortIndicesState(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices);
        ~GLSLVertexArraysShortIndicesState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysByteIndicesState
    
    class GLSLVertexArraysByteIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexArraysByteIndicesState(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices);
        ~GLSLVertexArraysByteIndicesState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysState
    
    class GLSLVertexArraysState: public GLSLDrawingState
    {
    public:
        GLSLVertexArraysState(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, vector<GLuint> &rElementsCounts);
        ~GLSLVertexArraysState();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
    };
}
