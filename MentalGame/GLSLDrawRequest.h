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
    class VertexBuffer;
    class IndexBuffer;
    class GLSLVertexArray;
    class GLSLAttributeInitializer;
    class UniformInitializer;
    class Attribute;
    class Uniform;
    
    
    
#pragma mark - GLSLDrawRequest
    
    class GLSLDrawRequest
    {
    public:
        GLSLDrawRequest();
        GLSLDrawRequest(const GLSLDrawRequest &rDrawRequest) = delete;
        virtual ~GLSLDrawRequest();
        
        void SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer);
        void SetUniformInitializer(UniformInitializer *pUniformInitializer);
        void SetRenderMode(GLSL_RENDER_MODE renderMode);
        void SetStartDrawIndex(GLint startDrawIndex);
        void SetDrawElementsCount(GLsizei drawElementsCount);
        
        GLSLAttributeInitializer * GetAttributeInitializer() const;
        UniformInitializer * GetUniformInitializer() const;
        GLSL_RENDER_MODE GetRenderMode() const;
        GLint GetStartDrawIndex() const;
        GLsizei GetDrawElementsCount() const;
        
        void ResetStartDrawIndex();
        void ResetDrawCount();
        void ResetStartDrawIndexAndDrawElementsCount();
        
        void Draw(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        
        virtual GLsizei GetVerticesCount() const = 0;
        
    protected:
        virtual void Activate() const = 0;
        virtual void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const = 0;
        virtual void Draw() const = 0;
        
    private:
        GLSLAttributeInitializer *m_attributeInitializer;
        UniformInitializer *m_uniformInitalizer;
        GLSL_RENDER_MODE m_renderMode;
        GLint m_startDrawIndex;
        GLsizei m_drawElementsCount;
    };
    
    
    
#pragma mark - VertexBufferIndexBufferRequest
    
    class VertexBufferIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferIndexBufferRequest(VertexBuffer *pVertexBuffer, IndexBuffer *pIndexBuffer);
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - VertexBufferShortIndicesRequest
    
    class VertexBufferShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferShortIndicesRequest(VertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        ~VertexBufferShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - VertexBufferByteIndicesRequest
    
    class VertexBufferByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferByteIndicesRequest(VertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        ~VertexBufferByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - VertexBufferRequest
    
    class VertexBufferRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferRequest(VertexBuffer *pVertexBuffer);
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArrayIndexBufferRequest
    
    class GLSLVertexArrayIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        GLSLVertexArrayIndexBufferRequest(GLSLVertexArray &rVertexArray, IndexBuffer *pIndexBuffer);
        ~GLSLVertexArrayIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
        IndexBuffer *m_indexBuffer;
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
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
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
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
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
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        GLSLVertexArray *m_vertexArray;
    };
    
    
    
#pragma mark - GLSLVertexArraysIndexBufferRequest
    
    class GLSLVertexArraysIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        GLSLVertexArraysIndexBufferRequest(vector<GLSLVertexArray> &rVertexArrays, IndexBuffer *pIndexBuffer);
        ~GLSLVertexArraysIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        IndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - GLSLVertexArraysShortIndicesRequest
    
    class GLSLVertexArraysShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        GLSLVertexArraysShortIndicesRequest(vector<GLSLVertexArray> &rVertexArrays, vector<GLushort> &rIndices);
        ~GLSLVertexArraysShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
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
        GLSLVertexArraysByteIndicesRequest(vector<GLSLVertexArray> &rVertexArrays, vector<GLubyte> &rIndices);
        ~GLSLVertexArraysByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
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
        GLSLVertexArraysRequest(vector<GLSLVertexArray> &rVertexArrays);
        ~GLSLVertexArraysRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
        void CalculateVerticesCount();
        
    private:
        vector<GLSLVertexArray *> *m_vertexArrays;
        GLsizei m_verticesCount;
    };
}
