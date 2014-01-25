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
#include <map>
#include "GLConstants.h"

using namespace std;



namespace Renderer
{
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    class GLSLVertexArray;
    class GLSLAttributeInitializer;
    class GLSLUniformInitializer;
    class GLSLAttribute;
    class GLSLUniform;
    
    
    
#pragma mark - GLSLDrawRequest
    
    class GLSLDrawRequest
    {
    public:
        GLSLDrawRequest();
        GLSLDrawRequest(const GLSLDrawRequest &rDrawRequest) = delete;
        virtual ~GLSLDrawRequest();
        
        void SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer);
        void SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer);
        void SetRenderMode(GLSL_RENDER_MODE renderMode);
        void SetStartDrawIndex(GLint startDrawIndex);
        void SetDrawElementsCount(GLsizei drawElementsCount);
        
        GLSLAttributeInitializer * GetAttributeInitializer() const;
        GLSLUniformInitializer * GetUniformInitializer() const;
        GLSL_RENDER_MODE GetRenderMode() const;
        GLint GetStartDrawIndex() const;
        GLsizei GetDrawElementsCount() const;
        
        void ResetStartDrawIndex();
        void ResetDrawCount();
        void ResetStartDrawIndexAndDrawElementsCount();
        
        void Draw(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        
        virtual GLsizei GetVerticesCount() const = 0;
        
    protected:
        virtual void Activate() const = 0;
        virtual void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const = 0;
        virtual void Draw() const = 0;
        
    private:
        GLSLAttributeInitializer *m_attributeInitializer;
        GLSLUniformInitializer *m_uniformInitalizer;
        GLSL_RENDER_MODE m_renderMode;
        GLint m_startDrawIndex;
        GLsizei m_drawElementsCount;
    };
    
    
    
#pragma mark - GLSLVertexBufferIndexBufferRequest
    
    class GLSLVertexBufferIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferIndexBufferRequest(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexBufferShortIndicesRequest
    
    class GLSLVertexBufferShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferShortIndicesRequest(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        ~GLSLVertexBufferShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferByteIndicesRequest
    
    class GLSLVertexBufferByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferByteIndicesRequest(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        ~GLSLVertexBufferByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexBufferRequest
    
    class GLSLVertexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexBufferRequest(GLSLVertexBuffer *pVertexBuffer);
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferRequest
    
    class GLSLVertexArrayIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayIndexBufferRequest(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer);
        ~GLSLVertexArrayIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayShortIndicesRequest
    
    class GLSLVertexArrayShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayShortIndicesRequest(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices);
        ~GLSLVertexArrayShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayByteIndicesRequest
    
    class GLSLVertexArrayByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayByteIndicesRequest(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices);
        ~GLSLVertexArrayByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArrayRequest
    
    class GLSLVertexArrayRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayRequest(GLSLVertexArray &rVertexArray);
        ~GLSLVertexArrayRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
    };
    
    
    
#pragma mark - GLSLVertexArraysIndexBufferRequest
    
    class GLSLVertexArraysIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        GLSLVertexArraysIndexBufferRequest(vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer);
        ~GLSLVertexArraysIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        GLSLIndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArraysShortIndicesRequest
    
    class GLSLVertexArraysShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        GLSLVertexArraysShortIndicesRequest(vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices);
        ~GLSLVertexArraysShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysByteIndicesRequest
    
    class GLSLVertexArraysByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        GLSLVertexArraysByteIndicesRequest(vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices);
        ~GLSLVertexArraysByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - GLSLVertexArraysRequest
    
    class GLSLVertexArraysRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        GLSLVertexArraysRequest(vector<GLSLVertexArray *> &rVertexArrays);
        ~GLSLVertexArraysRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, GLSLAttribute *> *pAttributes, map<string, GLSLUniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
    };
}
