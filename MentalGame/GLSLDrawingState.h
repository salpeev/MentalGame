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

using namespace std;



namespace GLRenderer
{
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    
    
#pragma mark - GLSLDrawingStateDelegate
    
    class GLSLDrawingStateDelegate
    {
    public:
        virtual void PerformAttributesInitialization(GLvoid *pData = NULL) const = 0;
    };
    
    
    
#pragma mark - GLSLDrawingState
    
    class GLSLDrawingState
    {
    public:
        GLSLDrawingState(GLSLDrawingStateDelegate *pDelegate);
        GLSLDrawingState(const GLSLDrawingState &rDrawingState) = delete;
        virtual ~GLSLDrawingState();
        
        GLSLDrawingStateDelegate * GetDelegate() const;
        
        void SetRenderMode(GLSL_RENDER_MODE renderMode);
        GLSL_RENDER_MODE GetRenderMode() const;
        
        void SetStartDrawIndex(GLint startDrawIndex);
        GLint GetStartDrawIndex() const;
        
        void SetDrawElementsCount(GLsizei drawElementsCount);
        GLsizei GetDrawElementsCount() const;
        
        void ResetStartDrawIndex();
        void ResetDrawCount();
        void ResetStartDrawIndexAndDrawElementsCount();
        
        // TODO: Why elements? Maybe should be renamed
        virtual GLsizei GetElementsCount() const = 0;
        virtual void PerformDrawing() const = 0;
        
    private:
        GLSLDrawingStateDelegate *m_delegate;
        
        GLSL_RENDER_MODE m_renderMode;
        GLint m_startDrawIndex;
        GLsizei m_drawElementsCount;
    };
    
    
    
#pragma mark - GLSLVertexBufferIndexBufferState
    
    class GLSLVertexBufferIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferIndexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate);
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesState
    
    class GLSLVertexBufferShortIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferShortIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexBufferShortIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesState
    
    class GLSLVertexBufferByteIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferByteIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexBufferByteIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferState
    
    class GLSLVertexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLDrawingStateDelegate *pDelegate);
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferState
    
    class GLSLVertexArrayIndexBufferState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLVertexArrayIndexBufferState(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArrayIndexBufferState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesState
    
    class GLSLVertexArrayShortIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLVertexArrayShortIndicesState(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArrayShortIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesState
    
    class GLSLVertexArrayByteIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLVertexArrayByteIndicesState(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArrayByteIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayState
    
    class GLSLVertexArrayState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLVertexArrayState(GLSLVertexArray &rVertexArray, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArrayState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
    };
    
    
    
#pragma mark - GLSLVertexArraysIndexBufferState
    
    class GLSLVertexArraysIndexBufferState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLVertexArraysIndexBufferState(vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArraysIndexBufferState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> m_vertexArrays;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArraysShortIndicesState
    
    class GLSLVertexArraysShortIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLVertexArraysShortIndicesState(vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArraysShortIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> m_vertexArrays;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysByteIndicesState
    
    class GLSLVertexArraysByteIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLVertexArraysByteIndicesState(vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArraysByteIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> m_vertexArrays;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysState
    
    class GLSLVertexArraysState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLVertexArraysState(vector<GLSLVertexArray *> &rVertexArrays, vector<GLuint> &rElementsCounts, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLVertexArraysState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> m_vertexArrays;
    };
}
