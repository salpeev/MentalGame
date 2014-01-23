//
//  GLSLProgramContainer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 19.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLProgramContainer.h"
#include "GLResourceManager.h"



namespace Renderer
{
    GLSLProgramContainer::GLSLProgramContainer()
    {
        LoadPositionColorProgram();
        LoadPerspectiveProgram();
    }
    
    GLSLProgram * GLSLProgramContainer::GetPositionColorProgram() const
    {
        return m_positionColorProgram;
    }
    
    GLSLProgram * GLSLProgramContainer::GetPerspectiveProgram() const
    {
        return m_perspectiveProgram;
    }
    
#pragma mark - Private Methods
    
    void GLSLProgramContainer::LoadPositionColorProgram()
    {
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.vsh");
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.fsh");
        
        m_positionColorProgram = new GLSLProgram(vertexShaderSource, fragmentShaderSource);
    }
    
    void GLSLProgramContainer::LoadPerspectiveProgram()
    {
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.vsh");
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.fsh");
        
        m_perspectiveProgram = new GLSLProgram(vertexShaderSource, fragmentShaderSource);
    }
}
