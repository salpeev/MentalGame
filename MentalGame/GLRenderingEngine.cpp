//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 08.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>
#include <iostream>
#include <vector>
#include "GLRenderingEngine.h"
#include "GLLogger.h"
#include "GLSLProgram.h"
#include "GLResourceManager.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLSLVertex.h"
#include "GLSLPositionColorDrawing.h"
#include "GLSLPerspectiveDrawing.h"

using namespace std;



namespace GLRenderer
{
    
    GLRenderingEngine::GLRenderingEngine(int width, int height)
    {
        m_drawings = new vector<GLSLDrawing *>;
        
        glViewport(0, 0, width, height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        Test0();
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
    }
    
    GLRenderingEngine::~GLRenderingEngine()
    {
        for (vector<GLSLDrawing *>::iterator iterator = m_drawings->begin(); iterator != m_drawings->end(); iterator++)
        {
            delete *iterator;
        }
        
        delete m_drawings;
    }
    
    void GLRenderingEngine::Render() const
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        for (vector<GLSLDrawing *>::iterator iterator = m_drawings->begin(); iterator != m_drawings->end(); iterator++)
        {
            GLSLDrawing *drawing = *iterator;
            drawing->Draw();
        }
    }
    
    void GLRenderingEngine::Test0() const
    {
        GLPoint point0(-0.5, -0.5, 0);
        GLPoint point1(0.5, -0.5, 0);
        
        GLColor color0(0, 1, 1);
        GLColor color1(1, 0, 1);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->LoadBufferData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        vector<GLubyte> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLIndexBuffer *indexBuffer = new GLSLIndexBuffer();
        indexBuffer->LoadBufferData(indexData);
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseVertexBufferWithIndexBuffer(vertexBuffer, indexBuffer);
        
        m_drawings->push_back(drawing);
    }
    
    void GLRenderingEngine::Test1() const
    {
        GLPoint point0(0.5, -0.5, 0);
        GLPoint point1(0.5, 0.5, 0);
        
        GLColor color0(1, 1, 1);
        GLColor color1(0, 1, 1);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->LoadBufferData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        vector<GLushort> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseVertexBufferWithIndices(vertexBuffer, indexData);
        
        m_drawings->push_back(drawing);
    }
    
    void GLRenderingEngine::Test2() const
    {
        GLPoint point0(0.5, 0.5, 0);
        GLPoint point1(-0.5, 0.5, 0);
        
        GLColor color0(1, 0, 0);
        GLColor color1(0, 1, 1);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->LoadBufferData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        vector<GLubyte> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseVertexBufferWithIndices(vertexBuffer, indexData);
        
        m_drawings->push_back(drawing);
    }
    
    void GLRenderingEngine::Test3() const
    {
        GLPoint point0(-1, -1, 0);
        GLPoint point1(1, 1, 0);
        
        GLColor color0(1, 0, 0);
        GLColor color1(0, 1, 0);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->LoadBufferData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseVertexBuffer(vertexBuffer);
        
        m_drawings->push_back(drawing);
    }
    
    void GLRenderingEngine::Test4() const
    {
        GLPoint point0(-0.5, 0.5, 0);
        GLPoint point1(-0.5, -0.5, 0);
        
        GLColor color0(1, 0, 0.2);
        GLColor color1(0.2, 1, 0);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        vector<GLushort> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLIndexBuffer *indexBuffer = new GLSLIndexBuffer();
        indexBuffer->LoadBufferData(indexData);
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseRawVertexDataWithIndexBuffer(&vertexData[0], sizeof(vertexData[0]) * vertexData.size(), indexBuffer);
        
        m_drawings->push_back(drawing);
    }
    
    void GLRenderingEngine::Test5() const
    {
        GLPoint point0(-1, 0, 0);
        GLPoint point1(1, 0, 0);
        
        GLColor color0(1, 1, 1);
        GLColor color1(1, 0, 0);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        vector<GLushort> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseRawVertexDataWithRawIndexData(&vertexData[0], sizeof(vertexData[0]) * vertexData.size(), indexData);
        
        m_drawings->push_back(drawing);
    }
    
    void GLRenderingEngine::Test6() const
    {
        GLPoint point0(0, -1, 0);
        GLPoint point1(0, 1, 0);
        
        GLColor color0(1, 0, 1);
        GLColor color1(0, 1, 0);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        vector<GLubyte> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseRawVertexDataWithRawIndexData(&vertexData[0], sizeof(vertexData[0]) * vertexData.size(), indexData);
        
        m_drawings->push_back(drawing);
    }
    
    void GLRenderingEngine::Test7() const
    {
        GLPoint point0(-1, 1, 0);
        GLPoint point1(1, -1, 0);
        
        GLColor color0(0, 0, 1);
        GLColor color1(1, 1, 0);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        GLSLDrawing *drawing = new GLSLPositionColorDrawing();
        drawing->Initialize();
        drawing->UseRawVertexData(&vertexData[0], sizeof(vertexData[0]), vertexData.size());
        
        m_drawings->push_back(drawing);
    }
}