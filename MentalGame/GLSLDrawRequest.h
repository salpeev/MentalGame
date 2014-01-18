//
//  GLSLDrawRequest.h
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
    
    
    
#pragma mark - GLSLDrawRequest
    
    class GLSLDrawRequest
    {
    public:
        GLSLDrawRequest(GLSLProgramInitializer *pProgramInitializer);
        GLSLDrawRequest(const GLSLDrawRequest &rDrawRequest) = delete;
        virtual ~GLSLDrawRequest();
        
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
    
    
    
#pragma mark - GLSLVertexBufferIndexBufferRequest
    
    class GLSLVertexBufferIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferIndexBufferRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesRequest
    
    class GLSLVertexBufferShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferShortIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        ~GLSLVertexBufferShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesRequest
    
    class GLSLVertexBufferByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferByteIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        ~GLSLVertexBufferByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferRequest
    
    class GLSLVertexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexBuffer *pVertexBuffer);
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferRequest
    
    class GLSLVertexArrayIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayIndexBufferRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer);
        ~GLSLVertexArrayIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesRequest
    
    class GLSLVertexArrayShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayShortIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices);
        ~GLSLVertexArrayShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesRequest
    
    class GLSLVertexArrayByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayByteIndicesRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices);
        ~GLSLVertexArrayByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayRequest
    
    class GLSLVertexArrayRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayRequest(GLSLProgramInitializer *pProgramInitializer, GLSLVertexArray &rVertexArray);
        ~GLSLVertexArrayRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
    };
    
    
    
#pragma mark - GLSLVertexArraysIndexBufferRequest
    
    class GLSLVertexArraysIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArraysIndexBufferRequest(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer);
        ~GLSLVertexArraysIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArraysShortIndicesRequest
    
    class GLSLVertexArraysShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArraysShortIndicesRequest(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices);
        ~GLSLVertexArraysShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysByteIndicesRequest
    
    class GLSLVertexArraysByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArraysByteIndicesRequest(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices);
        ~GLSLVertexArraysByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysRequest
    
    class GLSLVertexArraysRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArraysRequest(GLSLProgramInitializer *pProgramInitializer, vector<GLSLVertexArray *> &rVertexArrays, vector<GLuint> &rElementsCounts);
        ~GLSLVertexArraysRequest();
        
        GLsizei GetVerticesCount() const;
        void PerformDrawing() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
    };
}
