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

using namespace std;



namespace GLRenderer
{
    
    GLRenderingEngine::GLRenderingEngine(int width, int height)
    {
        glViewport(0, 0, width, height);
        
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
        vertexBuffer->LoadVertexData(&vertexData[0], sizeof(GLSLVertex1P1C), vertexData.size());
        
        
        m_drawing = new GLSLPositionColorDrawing();
        m_drawing->SetVertexBuffer(vertexBuffer);
#warning Crashed without this line. Should be refactored
        vertexBuffer->Bind();
        m_drawing->Initialize();
    }
    
    GLRenderingEngine::~GLRenderingEngine()
    {
        
    }
    
    void GLRenderingEngine::Render() const
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        m_drawing->Draw();
    }
    
}