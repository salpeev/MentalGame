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
#include "GLSLPositionColorInitializer.h"
#include "GLSLProjectionModelviewInitializer.h"
#include "GLSLProgramContainer.h"
#include "GLSLDrawRequest.h"
#include "GLSLVertexArray.h"
#include "ColorGlassDrawing.h"

using namespace std;



namespace Renderer
{
    
    GLRenderingEngine::GLRenderingEngine(int width, int height)
    {
        m_drawings = new vector<Drawing *>();
        
        glViewport(0, 0, width, height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
//        Test0();
//        Test1();
//        Test2();
//        Test3();
//        Test4();
//        Test5();
//        Test6();
//        Test7();
//        Test8();
//        Test9();
//        Test10();
//        Test11();
//        Test12();
        Test13();
    }
    
    GLRenderingEngine::~GLRenderingEngine()
    {
        
    }
    
    void GLRenderingEngine::Render() const
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        for (vector<Drawing *>::iterator iterator = m_drawings->begin(); iterator != m_drawings->end(); iterator++)
        {
            Drawing *drawing = *iterator;
            drawing->Draw();
        }
    }
    
    void GLRenderingEngine::Test0() const
    {
        GLPoint point0(-0.95, -0.95, 0);
        GLPoint point1(0.95, -0.95, 0);
        GLPoint point2(0.95, -0.9, 0);
        GLPoint point3(-0.95, -0.9, 0);
        GLPoint point4(-0.95, -0.85, 0);
        GLPoint point5(0.95, -0.85, 0);
        GLPoint point6(0.95, -0.80, 0);
        GLPoint point7(-0.95, -0.80, 0);
        
        GLColor color0(0.1, 0, 0);
        GLColor color1(0.2, 0, 0);
        GLColor color2(0.3, 0, 0);
        GLColor color3(0.4, 0, 0);
        GLColor color4(0.5, 0, 0);
        GLColor color5(0.6, 0, 0);
        GLColor color6(0.7, 0, 0);
        GLColor color7(0.8, 0, 0);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        GLSLVertex1P1C vertex2(point2, color2);
        GLSLVertex1P1C vertex3(point3, color3);
        GLSLVertex1P1C vertex4(point4, color4);
        GLSLVertex1P1C vertex5(point5, color5);
        GLSLVertex1P1C vertex6(point6, color6);
        GLSLVertex1P1C vertex7(point7, color7);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        vertexData.push_back(vertex2);
        vertexData.push_back(vertex3);
        vertexData.push_back(vertex4);
        vertexData.push_back(vertex5);
        vertexData.push_back(vertex6);
        vertexData.push_back(vertex7);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->LoadBufferData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        vector<GLushort> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        indexData.push_back(2);
        indexData.push_back(3);
        indexData.push_back(4);
        indexData.push_back(5);
        indexData.push_back(6);
        indexData.push_back(7);
        
        GLSLIndexBuffer *indexBuffer = new GLSLIndexBuffer();
        indexBuffer->LoadBufferData(indexData);
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLVertexBufferIndexBufferRequest *drawRequest = new GLSLVertexBufferIndexBufferRequest(vertexBuffer, indexBuffer);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        drawRequest->SetRenderMode(GLSL_RENDER_MODE_TRIANGLES);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
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
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexBufferShortIndicesRequest(vertexBuffer, indexData);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
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
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexBufferByteIndicesRequest(vertexBuffer, indexData);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
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
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexBufferRequest(vertexBuffer);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
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
        
        GLSLVertexArray vertexArray(&vertexData[0], sizeof(vertexData[0]), vertexData.size());
        
        GLSLIndexBuffer *indexBuffer = new GLSLIndexBuffer();
        indexBuffer->LoadBufferData(indexData);
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArrayIndexBufferRequest(vertexArray, indexBuffer);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
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
        
        GLSLVertexArray vertexArray(&vertexData[0], sizeof(vertexData[0]), vertexData.size());
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArrayShortIndicesRequest(vertexArray, indexData);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
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
        
        GLSLVertexArray vertexArray(&vertexData[0], sizeof(vertexData[0]), vertexData.size());
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArrayByteIndicesRequest(vertexArray, indexData);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
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
        
        GLSLVertexArray vertexArray(&vertexData[0], sizeof(vertexData[0]), vertexData.size());
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArrayRequest(vertexArray);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
    }
    
    void GLRenderingEngine::Test8() const
    {
        GLPoint point0(-2.0, -2.0, -5.0);
        GLPoint point1(2.0, -2.0, -5.0);
        GLPoint point2(2.0, 2.0, -5.0);
        GLPoint point3(-2.0, 2.0, -5.0);
        GLPoint point4(-2.0, -2.0, -7.0);
        GLPoint point5(2.0, -2.0, -7.0);
        GLPoint point6(2.0, 2.0, -7.0);
        GLPoint point7(-2.0, 2.0, -7.0);
        
//        GLPoint point0(-0.25, -0.25, -0.25);
//        GLPoint point1(0.25, -0.25, -0.25);
//        GLPoint point2(0.25, 0.25, -0.25);
//        GLPoint point3(-0.25, 0.25, -0.25);
//        GLPoint point4(-0.25, -0.25, 0.25);
//        GLPoint point5(0.25, -0.25, 0.25);
//        GLPoint point6(0.25, 0.25, 0.25);
//        GLPoint point7(-0.25, 0.25, 0.25);
        
        GLColor color0(0.0, 0.0, 0.5);
        GLColor color1(0.0, 0.5, 0.0);
        GLColor color2(0.5, 0.0, 0.0);
        GLColor color3(0.0, 0.5, 1.0);
        GLColor color4(0.5, 1.0, 0.0);
        GLColor color5(1.0, 0.0, 0.5);
        GLColor color6(0.5, 1.0, 1.0);
        GLColor color7(1.0, 1.0, 0.0);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        GLSLVertex1P1C vertex2(point2, color2);
        GLSLVertex1P1C vertex3(point3, color3);
        GLSLVertex1P1C vertex4(point4, color4);
        GLSLVertex1P1C vertex5(point5, color5);
        GLSLVertex1P1C vertex6(point6, color6);
        GLSLVertex1P1C vertex7(point7, color7);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        vertexData.push_back(vertex2);
        vertexData.push_back(vertex3);
        vertexData.push_back(vertex4);
        vertexData.push_back(vertex5);
        vertexData.push_back(vertex6);
        vertexData.push_back(vertex7);
        
        vector<GLushort> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        indexData.push_back(1);
        indexData.push_back(2);
        indexData.push_back(2);
        indexData.push_back(3);
        indexData.push_back(3);
        indexData.push_back(0);
        indexData.push_back(4);
        indexData.push_back(5);
        indexData.push_back(5);
        indexData.push_back(6);
        indexData.push_back(6);
        indexData.push_back(7);
        indexData.push_back(7);
        indexData.push_back(4);
        indexData.push_back(0);
        indexData.push_back(4);
        indexData.push_back(1);
        indexData.push_back(5);
        indexData.push_back(2);
        indexData.push_back(6);
        indexData.push_back(3);
        indexData.push_back(7);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->LoadBufferData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        GLSLIndexBuffer *indexBuffer = new GLSLIndexBuffer();
        indexBuffer->LoadBufferData(indexData);
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        GLSLProjectionModelviewInitializer *uniformInitializer = new GLSLProjectionModelviewInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexBufferIndexBufferRequest(vertexBuffer, indexBuffer);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        drawRequest->SetUniformInitializer(uniformInitializer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
    }
    
    void GLRenderingEngine::Test9() const {
        GLPoint point0(-1.0, 0.0, 0.0);
        GLPoint point1(0.0, -1.0, 0.0);
        
        GLColor color0(0.7, 0.1, 0.3);
        GLColor color1(1.0, 1.0, 1.0);
        
        vector<GLPoint> pointData;
        pointData.push_back(point0);
        pointData.push_back(point1);
        
        vector<GLColor> colorData;
        colorData.push_back(color0);
        colorData.push_back(color1);
        
        GLSLVertexArray pointArray(&pointData[0], sizeof(GLPoint), pointData.size());
        GLSLVertexArray colorArray(&colorData[0], sizeof(GLColor), colorData.size());
        
        vector<GLSLVertexArray> vertexArrays;
        vertexArrays.push_back(pointArray);
        vertexArrays.push_back(colorArray);
        
        vector<GLushort> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLIndexBuffer *indexBuffer = new GLSLIndexBuffer();
        indexBuffer->LoadBufferData(indexData);
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArraysIndexBufferRequest(vertexArrays, indexBuffer);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
    }
    
    void GLRenderingEngine::Test10() const {
        GLPoint point0(0.0, -1.0, 0.0);
        GLPoint point1(1.0, 0.0, 0.0);
        
        GLColor color0(0.0, 1.0, 0.0);
        GLColor color1(1.0, 0.0, 1.0);
        
        vector<GLPoint> pointData;
        pointData.push_back(point0);
        pointData.push_back(point1);
        
        vector<GLColor> colorData;
        colorData.push_back(color0);
        colorData.push_back(color1);
        
        GLSLVertexArray pointArray(&pointData[0], sizeof(GLPoint), pointData.size());
        GLSLVertexArray colorArray(&colorData[0], sizeof(GLColor), colorData.size());
        
        vector<GLSLVertexArray> vertexArrays;
        vertexArrays.push_back(pointArray);
        vertexArrays.push_back(colorArray);
        
        vector<GLushort> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArraysShortIndicesRequest(vertexArrays, indexData);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
    }
    
    void GLRenderingEngine::Test11() const {
        GLPoint point0(1.0, 0.0, 0.0);
        GLPoint point1(0.0, 1.0, 0.0);
        
        GLColor color0(0.5, 1.0, 0.0);
        GLColor color1(0.5, 0.0, 1.0);
        
        vector<GLPoint> pointData;
        pointData.push_back(point0);
        pointData.push_back(point1);
        
        vector<GLColor> colorData;
        colorData.push_back(color0);
        colorData.push_back(color1);
        
        GLSLVertexArray pointArray(&pointData[0], sizeof(GLPoint), pointData.size());
        GLSLVertexArray colorArray(&colorData[0], sizeof(GLColor), colorData.size());
        
        vector<GLSLVertexArray> vertexArrays;
        vertexArrays.push_back(pointArray);
        vertexArrays.push_back(colorArray);
        
        vector<GLubyte> indexData;
        indexData.push_back(0);
        indexData.push_back(1);
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArraysByteIndicesRequest(vertexArrays, indexData);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
    }
    
    void GLRenderingEngine::Test12() const {
        GLPoint point0(0.0, 1.0, 0.0);
        GLPoint point1(-1.0, 0.0, 0.0);
        
        GLColor color0(0.5, 0.5, 1.0);
        GLColor color1(0.0, 1.0, 0.5);
        
        vector<GLPoint> pointData;
        pointData.push_back(point0);
        pointData.push_back(point1);
        
        vector<GLColor> colorData;
        colorData.push_back(color0);
        colorData.push_back(color1);
        
        GLSLVertexArray pointArray(&pointData[0], sizeof(GLPoint), pointData.size());
        GLSLVertexArray colorArray(&colorData[0], sizeof(GLColor), colorData.size());
        
        vector<GLSLVertexArray> vertexArrays;
        vertexArrays.push_back(pointArray);
        vertexArrays.push_back(colorArray);
        
        GLSLPositionColorInitializer *attribInitizlizer = new GLSLPositionColorInitializer();
        
        GLSLDrawRequest *drawRequest = new GLSLVertexArraysRequest(vertexArrays);
        drawRequest->SetAttributeInitializer(attribInitizlizer);
        
        GLSLProgram *pProgram = GLSLProgramContainer::SharedInstance().GetPositionColorProgram();
        pProgram->ExecuteDrawRequest(drawRequest);
    }
    
    void GLRenderingEngine::Test13() const {
        ColorGlassDrawing *colorGlassDrawing = new ColorGlassDrawing();
        m_drawings->push_back(colorGlassDrawing);
    }
}