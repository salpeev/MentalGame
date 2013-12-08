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
        // Zero
        GLPoint point0(-1, -1, 0);
        GLPoint point1(1, 1, 0);
        
        GLColor color0(1, 0, 0, 1);
        GLColor color1(0, 1, 0, 1);
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        vector<GLSLVertex1P1C> vertexData;
        vertexData.push_back(vertex0);
        vertexData.push_back(vertex1);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->LoadBufferData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        GLSLDrawing *drawing0 = new GLSLPositionColorDrawing();
        drawing0->Initialize();
        drawing0->UseVertexBuffer(vertexBuffer);
        
        m_drawings->push_back(drawing0);
    }
    
    void GLRenderingEngine::Test1() const
    {
        
    }
}