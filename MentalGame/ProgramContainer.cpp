//
//  ProgramContainer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 19.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ProgramContainer.h"
#include "ResourceManager.h"



namespace Renderer {
    
    ProgramContainer::ProgramContainer() {
        LoadPositionColorProgram();
        LoadPerspectiveProgram();
        LoadTextureProgram();
        LoadGlassProgram();
    }
    
    Program * ProgramContainer::GetPositionColorProgram() const {
        return m_positionColorProgram;
    }
    
    Program * ProgramContainer::GetPerspectiveProgram() const {
        return m_perspectiveProgram;
    }
    
    Program * ProgramContainer::GetTextureProgram() const {
        return m_textureProgram;
    }
    
    Program * ProgramContainer::GetGlassProgram() const {
        return m_glassProgram;
    }
    
#pragma mark - Private Methods
    
    void ProgramContainer::LoadPositionColorProgram() {
        string vertexShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.vsh");
        string fragmentShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("PositionColorShader.fsh");
        
        m_positionColorProgram = new Program(vertexShaderSource, fragmentShaderSource);
    }
    
    void ProgramContainer::LoadPerspectiveProgram() {
        string vertexShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.vsh");
        string fragmentShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.fsh");
        
        m_perspectiveProgram = new Program(vertexShaderSource, fragmentShaderSource);
    }
    
    void ProgramContainer::LoadTextureProgram() {
        string vertexShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("TextureShader.vsh");
        string fragmentShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("TextureShader.fsh");
        
        m_textureProgram = new Program(vertexShaderSource, fragmentShaderSource);
    }
    
    void ProgramContainer::LoadGlassProgram() {
        string vertexShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("GlassShader.vsh");
        string fragmentShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("GlassShader.fsh");
        
        m_glassProgram = new Program(vertexShaderSource, fragmentShaderSource);
    }
}
