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
    
    
    
    class GLSLDrawingState
    {
    public:
        GLSLDrawingState();
        GLSLDrawingState(const GLSLDrawingState &rDrawingState) = delete;
        virtual ~GLSLDrawingState();
        
        virtual void Activate() const = 0;
    };
    
    
    
    class GLSLVertexBufferIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferIndexBufferState(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        
        void Activate() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
    class GLSLVertexBufferShortIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferShortIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        ~GLSLVertexBufferShortIndicesState();
        
        void Activate() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLushort> *m_indices;
    };
    
    
    
    class GLSLVertexBufferByteIndicesState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferByteIndicesState(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        ~GLSLVertexBufferByteIndicesState();
        
        void Activate() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLubyte> *m_indices;
    };
    
    
    
    class GLSLVertexBufferState: public GLSLDrawingState
    {
    public:
        GLSLVertexBufferState(GLSLVertexBuffer *pVertexBuffer);
        
        void Activate() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
    };
    
    
    
    class GLSLRawVertexDataIndexBufferState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataIndexBufferState(GLvoid *pData, GLsizei dataSize, GLSLIndexBuffer *pIndexBuffer);
        ~GLSLRawVertexDataIndexBufferState();
        
        void Activate() const;
        
    private:
        GLvoid *m_data;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
    class GLSLRawVertexDataRawShortIndicesState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataRawShortIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLushort> &rIndices);
        ~GLSLRawVertexDataRawShortIndicesState();
        
        void Activate() const;
        
    private:
        GLvoid *m_data;
        vector<GLushort> *m_indices;
    };
    
    
    
    class GLSLRawVertexDataRawByteIndicesState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataRawByteIndicesState(GLvoid *pData, GLsizei dataSize, vector<GLubyte> &rIndices);
        ~GLSLRawVertexDataRawByteIndicesState();
        
        void Activate() const;
        
    private:
        GLvoid *m_data;
        vector<GLubyte> *m_indices;
    };
    
    
    
    class GLSLRawVertexDataState: public GLSLDrawingState
    {
    public:
        GLSLRawVertexDataState(GLvoid *pData, GLsizei dataSize);
        ~GLSLRawVertexDataState();
        
        void Activate() const;
        
    private:
        GLvoid *m_data;
    };
}
