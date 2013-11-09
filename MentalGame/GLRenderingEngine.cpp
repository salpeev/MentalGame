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
#include "GLSLVertex.h"

using namespace std;



namespace GLRenderer
{
    
    GLRenderingEngine::GLRenderingEngine(int width, int height)
    {
        glViewport(0, 0, width, height);
        
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.vsh");
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.fsh");
        
        GLSLShader *vertexShader = new GLSLShader(GL_VERTEX_SHADER, &vertexShaderSource);
        GLSLShader *fragmentShader = new GLSLShader(GL_FRAGMENT_SHADER, &fragmentShaderSource);
        
        GLSLProgram *program = new GLSLProgram(vertexShader, fragmentShader);
        program->Use();
        
        
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
        vertexBuffer->Bind();
        vertexBuffer->LoadVertexData(&vertexData[0], sizeof(vertexData[0]) * vertexData.size());
        
        for (GLuint i = 0; i < program->GetAttributesCount(); i++)
        {
            GLSLAttribute *attribute = program->GetAttributeAtIndex(i);
            attribute->EnableArray();
            
            GLuint attribLocation = attribute->GetLocation();
            
            glEnableVertexAttribArray(attribute->GetLocation());
            
            if (attribute->GetName()->compare("a_position") == 0)
            {
                glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), NULL);
            }
            else if (attribute->GetName()->compare("a_color") == 0)
            {
                glVertexAttribPointer(attribLocation, 4, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), (GLvoid *)(sizeof(GLSLVertex1P1C::m_position)));
            }
            
            cout << *(attribute->GetName()) << endl;
        }
    }
    
    GLRenderingEngine::~GLRenderingEngine()
    {
        
    }
    
    void GLRenderingEngine::Render() const
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawArrays(GL_LINES, 0, 2);
    }
    
}