//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 08.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>
#include <iostream>
#include "GLRenderingEngine.h"
#include "GLLogger.h"
#include "GLSLProgram.h"
#include "GLResourceManager.h"
#include "GLSLVertexBuffer.h"

using namespace std;



namespace GLRenderer
{
    
    GLRenderingEngine::GLRenderingEngine(int width, int height)
    {
        glViewport(0, 0, width, height);
        
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("Shader.vsh");
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("Shader.fsh");
        
        GLSLShader *vertexShader = new GLSLShader(GL_VERTEX_SHADER, &vertexShaderSource);
        GLSLShader *fragmentShader = new GLSLShader(GL_FRAGMENT_SHADER, &fragmentShaderSource);
        
        GLSLProgram *program = new GLSLProgram(vertexShader, fragmentShader);
        program->Use();
        
        
        GLPoint point0(-1, -1, 0);
        GLPoint point1(1, 1, 0);
        
        GLColor color0(1, 0, 0, 1);
        GLColor color1(0, 1, 0, 1);
        
        GLSLVertex1P1C *vertex0 = new GLSLVertex1P1C(point0, color0);
        GLSLVertex1P1C *vertex1 = new GLSLVertex1P1C(point1, color1);
        
        GLSLVertexData1P1C *vertexData = new GLSLVertexData1P1C();
        vertexData->AddVertex(vertex0);
        vertexData->AddVertex(vertex1);
        
        GLSLVertexBuffer *vertexBuffer = new GLSLVertexBuffer();
        vertexBuffer->Bind();
        vertexBuffer->LoadVertexData(vertexData, GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        for (GLuint i = 0; i < program->GetAttributesCount(); i++)
        {
            GLSLAttribute *attribute = program->GetAttributeAtIndex(i);
            attribute->EnableArray();
            
            if (attribute->GetName()->compare("a_position") == 0)
            {
                
            }
            else if (attribute->GetName()->compare("a_color") == 0)
            {
                
            }
            
            cout << *(attribute->GetName()) << endl;
        }
    }
    
    GLRenderingEngine::~GLRenderingEngine()
    {
        
    }
    
    void GLRenderingEngine::Render() const
    {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
}