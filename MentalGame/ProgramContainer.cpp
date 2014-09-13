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
        LoadNormalTextureProgram();
        LoadCausticTextureProgram();
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
    
    Program * ProgramContainer::GetNormalTextureProgram() const {
        return m_normalTextureProgram;
    }
    
    Program * ProgramContainer::GetCausticTextureProgram() const {
        return m_causticTextureProgram;
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
    
    void ProgramContainer::LoadNormalTextureProgram() {
        string vertexShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("NormalTextureShader.vsh");
        string fragmentShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("NormalTextureShader.fsh");
        
        m_normalTextureProgram = new Program(vertexShaderSource, fragmentShaderSource);
    }
    
    void ProgramContainer::LoadCausticTextureProgram() {
        string vertexShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("CausticTextureShader.vsh");
        string fragmentShaderSource = ResourceManager::SharedInstance().LoadTextFileNamed("CausticTextureShader.fsh");
        
        m_causticTextureProgram = new Program(vertexShaderSource, fragmentShaderSource);
    }
}
