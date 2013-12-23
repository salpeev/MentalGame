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

using namespace std;



namespace GLRenderer
{
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    
    
#pragma mark - GLSLDrawingStateDelegate
    
    class GLSLDrawingStateDelegate
    {
    public:
        virtual void InitializeAttributes(GLvoid *pData = NULL) const = 0;
    };
    
    
    
#pragma mark - GLSLDrawingState
    
    class GLSLDrawingState
    {
    public:
        GLSLDrawingState(GLSLDrawingStateDelegate *pDelegate);
        GLSLDrawingState(const GLSLDrawingState &rDrawingState) = delete;
        virtual ~GLSLDrawingState();
        
        GLSLDrawingStateDelegate * GetDelegate() const;
        
        virtual void PerformDrawing() const = 0;
        
    private:
        GLSLDrawingStateDelegate *m_delegate;
    };
    
    
    
#pragma mark - GLSLVertexBufferIndexBufferState
    
    class GLSLVertexBufferIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferIndexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate);
        
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
        
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
    };
    
    
    
#pragma mark - GLSLRawVertexDataIndexBufferState
    
    class GLSLRawVertexDataIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataIndexBufferState(GLvoid *pData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataIndexBufferState();
        
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLRawVertexDataRawShortIndicesState
    
    class GLSLRawVertexDataRawShortIndicesState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataRawShortIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLushort> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataRawShortIndicesState();
        
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLRawVertexDataRawByteIndicesState
    
    class GLSLRawVertexDataRawByteIndicesState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataRawByteIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLubyte> &rIndices, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataRawByteIndicesState();
        
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLRawVertexDataState
    
    class GLSLRawVertexDataState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataState(GLvoid *pData, GLsizei elementSize, GLuint elementsCount, GLSLDrawingStateDelegate *pDelegate);
        ~GLSLRawVertexDataState();
        
        void PerformDrawing() const;
        
    private:
        GLvoid *m_data;
        GLuint m_elementsCount;
    };
}
