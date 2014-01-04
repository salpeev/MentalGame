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
    
    
    
#pragma mark - GLSLRawVertexDataIndexBufferState
    
    class GLSLRawVertexDataIndexBufferState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLRawVertexDataIndexBufferState(GLvoid *pData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataIndexBufferState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLRawVertexDataRawShortIndicesState
    
    class GLSLRawVertexDataRawShortIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLRawVertexDataRawShortIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataRawShortIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLRawVertexDataRawByteIndicesState
    
    class GLSLRawVertexDataRawByteIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLRawVertexDataRawByteIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataRawByteIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLRawVertexDataState
    
    class GLSLRawVertexDataState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass GLSLVertexData pointer instead
        GLSLRawVertexDataState(GLvoid *pData, GLsizei elementSize, GLuint elementsCount, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        GLuint m_elementsCount;
    };
    
#pragma mark - GLSLRawVertexDataArraysIndexBufferState
    
    class GLSLRawVertexDataArraysIndexBufferState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLRawVertexDataArraysIndexBufferState(vector<GLvoid *> &rDataArrays, vector<GLsizei> &rElementSizes, vector<GLuint> &rElementsCounts, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataArraysIndexBufferState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLvoid *> *m_dataArrays;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
#pragma mark - GLSLRawVertexDataArraysRawShortIndicesState
    
    class GLSLRawVertexDataArraysRawShortIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLRawVertexDataArraysRawShortIndicesState(vector<GLvoid *> &rDataArrays, vector<GLsizei> &rElementSizes, vector<GLuint> &rElementsCounts, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataArraysRawShortIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLvoid *> m_dataArrays;
        vector<GLushort> *m_indices;
    };
    
#pragma mark - GLSLRawVertexDataArraysRawByteIndicesState
    
    class GLSLRawVertexDataArraysRawByteIndicesState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLRawVertexDataArraysRawByteIndicesState(vector<GLvoid *> &rDataArrays, vector<GLsizei> &rElementSizes, vector<GLuint> &rElementsCounts, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataArraysRawByteIndicesState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLvoid *> m_dataArrays;
        vector<GLubyte> *m_indices;
    };
    
#pragma mark - GLSLRawVertexDataArraysState
    
    class GLSLRawVertexDataArraysState: public GLSLDrawingState
    {
    public:
        // TODO: All this parameters can be wrapped in a single object. For example GLSLVertexData. Then pass vector<GLSLVertexData *> instead
        GLSLRawVertexDataArraysState(vector<GLvoid *> &rDataArrays, vector<GLsizei> &rElementSizes, vector<GLuint> &rElementsCounts, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataArraysState();
        
        GLsizei GetElementsCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLvoid *> m_dataArrays;
        GLuint m_elementsCount;
    };
}
