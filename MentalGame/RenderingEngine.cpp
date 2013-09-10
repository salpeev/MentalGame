//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 08.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "RenderingEngine.h"
#include "GLSLProgram.h"
#include "ResourceManager.h"
#include <OpenGLES/ES2/gl.h>



namespace Renderer
{
    
    RenderingEngine::RenderingEngine(int width, int height)
    {
        glViewport(0, 0, width, height);
        
        string vertexShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("Shader.vsh");
        GLSLShader vertexShader(GL_VERTEX_SHADER, &vertexShaderSource);
    }
    
    RenderingEngine::~RenderingEngine()
    {
        
    }
    
    void RenderingEngine::Render() const
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        
        //    glDrawArrays(GL_LINES, 0, 2);
    }
    
}