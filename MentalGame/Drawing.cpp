//
//  Drawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Drawing.h"
#include "GLSLAttributeInitializer.h"
#include "GLSLUniformInitializer.h"
#include "GLSLDrawRequest.h"



namespace Renderer {
    
    Drawing::Drawing(): m_drawRequest(NULL), m_attributeInitializer(NULL), m_uniformInitializer(NULL) {
        
    }
    
    Drawing::Drawing(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer): Drawing() {
        
    }
    
    Drawing::Drawing(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices): Drawing() {
        
    }
    
    Drawing::Drawing(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices): Drawing() {
        
    }
    
    Drawing::Drawing(GLSLVertexBuffer *pVertexBuffer): Drawing() {
        
    }
    
    Drawing::Drawing(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer): Drawing() {
        
    }
    
    Drawing::Drawing(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices): Drawing() {
        
    }
    
    Drawing::Drawing(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices): Drawing() {
        
    }
    
    Drawing::Drawing(GLSLVertexArray &rVertexArray): Drawing() {
        
    }
    
    Drawing::Drawing(vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer): Drawing() {
        
    }
    
    Drawing::Drawing(vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices): Drawing() {
        
    }
    
    Drawing::Drawing(vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices): Drawing() {
        
    }
    
    Drawing::Drawing(vector<GLSLVertexArray *> &rVertexArrays): Drawing() {
        
    }
    
    Drawing::~Drawing() {
        delete m_drawRequest;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
    }
    
#pragma mark - Public Methods
    
    void Drawing::UseData(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexBufferIndexBufferRequest(pVertexBuffer, pIndexBuffer);
    }
    
    void Drawing::UseData(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexBufferShortIndicesRequest(pVertexBuffer, rIndices);
    }
    
    void Drawing::UseData(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexBufferByteIndicesRequest(pVertexBuffer, rIndices);
    }
    
    void Drawing::UseData(GLSLVertexBuffer *pVertexBuffer) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexBufferRequest(pVertexBuffer);
    }
    
    void Drawing::UseData(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArrayIndexBufferRequest(rVertexArray, pIndexBuffer);
    }
    
    void Drawing::UseData(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArrayShortIndicesRequest(rVertexArray, rIndices);
    }
    
    void Drawing::UseData(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArrayByteIndicesRequest(rVertexArray, rIndices);
    }
    
    void Drawing::UseData(GLSLVertexArray &rVertexArray) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArrayRequest(rVertexArray);
    }
    
    void Drawing::UseData(vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArraysIndexBufferRequest(rVertexArrays, pIndexBuffer);
    }
    
    void Drawing::UseData(vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArraysShortIndicesRequest(rVertexArrays, rIndices);
    }
    
    void Drawing::UseData(vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArraysByteIndicesRequest(rVertexArrays, rIndices);
    }
    
    void Drawing::UseData(vector<GLSLVertexArray *> &rVertexArrays) {
        delete m_drawRequest;
        m_drawRequest = new GLSLVertexArraysRequest(rVertexArrays);
    }
    
    
#pragma mark - Protected Methods
    
    void Drawing::SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer) {
        
    }
    
    void Drawing::SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer) {
        
    }
    
    GLSLAttributeInitializer * Drawing::GetAttributeInitializer() const {
        return m_attributeInitializer;
    }
    
    GLSLUniformInitializer * Drawing::GetUniformInitializer() const {
        return m_uniformInitializer;
    }
}