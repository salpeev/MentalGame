//
//  Shader.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Shader.h"
#include "Logger.h"
#include <iostream>



namespace Renderer {
    
#pragma mark - Lifecycle
    
    Shader::Shader(GLSL_SHADER_TYPE type, const string &rSource) {
        SetType(type);
        SetSource(rSource);
        Compile();
    }
    
    Shader::~Shader() {
        Delete();
    }
    
#pragma mark - Public Methods
    
    GLuint Shader::GetShaderHandle() const {
        return m_shaderHandle;
    }
    
    bool Shader::IsCompiled() const {
        GLint compileStatus;
        glGetShaderiv(m_shaderHandle, GLSL_SHADER_IV_COMPILE_STATUS, &compileStatus);
        
        CheckError();
        
        return (compileStatus == GLSL_TRUE);
    }
    
#pragma mark - Private Methods
    
    void Shader::SetType(GLSL_SHADER_TYPE type) {
        m_shaderHandle = glCreateShader(type);
        CheckError();
        
        if (m_shaderHandle == 0) {
            Log("Unable to create shader");
        }
    }
    
    void Shader::SetSource(const string &rSource) {
        const char *sourceCStr = rSource.c_str();
        glShaderSource(m_shaderHandle, 1, &sourceCStr, NULL);
        
        CheckError();
    }
    
    void Shader::Compile() const {
        glCompileShader(m_shaderHandle);
        CheckError();
        
        if (!IsCompiled()) {
            GLint infoLength;
            glGetShaderiv(m_shaderHandle, GLSL_SHADER_IV_INFO_LOG_LENGTH, &infoLength);
            
            if (infoLength > 1) {
                char *infoLog = (char *)malloc(sizeof(char) * infoLength);
                
                glGetShaderInfoLog(m_shaderHandle, infoLength, NULL, infoLog);
                Log("SHADER: %s", infoLog);
                
                free(infoLog);
            }
        }
    }
    
    void Shader::Delete() {
        if (!IsDeleted()) {
            glDeleteShader(m_shaderHandle);
            m_shaderHandle = 0;
            
            CheckError();
        }
    }
    
    bool Shader::IsDeleted() const {
        GLint deleteStatus;
        glGetShaderiv(m_shaderHandle, GLSL_SHADER_IV_DELETE_STATUS, &deleteStatus);
        
        CheckError();
        
        return (deleteStatus == GLSL_TRUE);
    }
}