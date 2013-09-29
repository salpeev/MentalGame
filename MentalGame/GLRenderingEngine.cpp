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
        
        
        GLPoint2 point0(-1, -1);
        GLPoint2 point1(1, 1);
        
        GLColor color0(1, 0, 0, 1);
        GLColor color1(0, 1, 0, 1);
        
        GLSLVertexData vertexData;
        vertexData.AddPoint2(point0);
        vertexData.AddColor(color0);
        vertexData.AddPoint2(point1);
        vertexData.AddColor(color1);
        
        GLSLVertexBuffer vertexBuffer;
        vertexBuffer.Bind();
        vertexBuffer.LoadVertexData(&vertexData, GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        for (GLuint i = 0; i < program->GetAttributesCount(); i++)
        {
            GLSLAttribute *attribute = program->GetAttributeAtIndex(i);
            cout << attribute->GetName() << endl;
        }
        
//        delete program;
//        delete vertexShader;
//        delete fragmentShader;
    }
    
    GLRenderingEngine::~GLRenderingEngine()
    {
        
    }
    
    void GLRenderingEngine::Render() const
    {
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
        
        
//        GLfloat vertices[] =
//        {
//            0.0f, 0.0f, 0.0f,
//            1.0f, 1.0f, 0.0f
//        };
        
        //    glDrawArrays(GL_LINES, 0, 2);
    }
    
}