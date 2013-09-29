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
        
        GLSLVertex1P1C vertex0(point0, color0);
        GLSLVertex1P1C vertex1(point1, color1);
        
        GLSLVertexData vertexData;
        vertexData.AddVertex1P1C(vertex0);
        vertexData.AddVertex1P1C(vertex1);
        
        GLSLVertexBuffer vertexBuffer;
        vertexBuffer.Bind();
        vertexBuffer.LoadVertexData(&vertexData, GLSL_BUFFER_USAGE_STATIC_DRAW);
        
        GLuint offset = 0;
        for (GLuint i = 0; i < program->GetAttributesCount(); i++)
        {
            GLSLAttribute *attribute = program->GetAttributeAtIndex(i);
            if (attribute->GetName()->compare("a_position") == 0)
            {
                switch (attribute->GetType()) {
                    case GL_FLOAT_VEC3:
                        cout << "vec3" << endl;
                        break;
                    case GL_FLOAT_VEC4:
                        cout << "vec4" << endl;
                        break;
                }
                offset += sizeof(GLPoint) / sizeof(GLfloat);
            }
            else if (attribute->GetName()->compare("a_color") == 0)
            {
                offset += sizeof(GLColor) / sizeof(GLfloat);
            }
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