//
//  GLSLShader.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLShader.h"
#include "Logger.h"
#include <iostream>



namespace Renderer
{
    GLSLShader::GLSLShader(): m_shaderHandle(0)
    {
        
    }
    
    GLSLShader::GLSLShader(GLenum type, const string *source): GLSLShader()
    {
        SetType(type);
        SetSource(source);
        Compile();
    }
    
    GLSLShader::~GLSLShader()
    {
        glDeleteShader(m_shaderHandle);
    }
    
    void GLSLShader::SetType(GLenum type)
    {
        m_shaderHandle = glCreateShader(type);
        
        if (m_shaderHandle == 0)
        {
            CheckError();
        }
    }
    
    void GLSLShader::SetSource(const string *source)
    {
        const char *sourceCStr = source->c_str();
        glShaderSource(m_shaderHandle, 1, &sourceCStr, NULL);
        
        CheckError();
    }
    
    GLuint GLSLShader::GetShaderHandle() const
    {
        return m_shaderHandle;
    }
    
    bool GLSLShader::Compile() const
    {
        glCompileShader(m_shaderHandle);
        
        if (CheckError()) {
            return false;
        }
        
        if (!IsCompiled())
        {
            GLint infoLength;
            glGetShaderiv(m_shaderHandle, GL_INFO_LOG_LENGTH, &infoLength);
            
            if (infoLength > 1)
            {
                char *infoLog = (char *)malloc(sizeof(char *) * infoLength);
                
                glGetShaderInfoLog(m_shaderHandle, infoLength, NULL, infoLog);
                Log("SHADER: %s", infoLog);
                
                free(infoLog);
            }
            
            return false;
        }
        
        return true;
    }
    
    bool GLSLShader::IsCompiled() const
    {
        GLint compileStatus;
        glGetShaderiv(m_shaderHandle, GL_COMPILE_STATUS, &compileStatus);
        
        CheckError();
        
        return (compileStatus == GL_TRUE);
    }
}