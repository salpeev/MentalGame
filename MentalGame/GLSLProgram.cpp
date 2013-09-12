//
//  Program.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLProgram.h"
#include "Logger.h"
#include <iostream>



namespace Renderer
{
    GLSLProgram::GLSLProgram(): m_programHandle(0)
    {
        m_programHandle = glCreateProgram();
    }
    
    GLSLProgram::GLSLProgram(GLSLShader *pVertexShader, GLSLShader *pFragmentShader): GLSLProgram()
    {
        SetVertexShader(pVertexShader);
        SetFragmentShader(pFragmentShader);
        
        Link();
    }
    
    GLSLProgram::~GLSLProgram()
    {
        glDeleteProgram(m_programHandle);
    }
    
    void GLSLProgram::SetVertexShader(GLSLShader *pVertexShader)
    {
        p_vertexShader = pVertexShader;
    }
    
    void GLSLProgram::SetFragmentShader(GLSLShader *pFragmentShader)
    {
        p_fragmentShader = pFragmentShader;
    }
    
    void GLSLProgram::Activate() const
    {
        glUseProgram(m_programHandle);
    }
    
    GLuint GLSLProgram::GetProgramHandle() const
    {
        return m_programHandle;
    }
    
    bool GLSLProgram::Link() const
    {
        glAttachShader(m_programHandle, p_vertexShader->GetShaderHandle());
        CheckError();
        glAttachShader(m_programHandle, p_fragmentShader->GetShaderHandle());
        CheckError();
        
        glLinkProgram(m_programHandle);
        CheckError();
        
        if (IsLinked())
        {
            GLint infoLength;
            glGetProgramiv(m_programHandle, GL_INFO_LOG_LENGTH, &infoLength);
            
            if (infoLength > 1)
            {
                char *infoLog = (char *)malloc(sizeof(char) * infoLength);
                
                glGetProgramInfoLog(m_programHandle, infoLength, NULL, infoLog);
                Log("PROGRAM: %s", infoLog);
                
                free(infoLog);
            }
            
            return false;
        }
        
        return true;
    }
    
    bool GLSLProgram::IsLinked() const
    {
        GLint linkStatus;
        glGetProgramiv(m_programHandle, GL_LINK_STATUS, &linkStatus);
        
        CheckError();
        
        return (linkStatus == GL_TRUE);
    }
}