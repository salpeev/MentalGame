//
//  Program.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLProgram.h"
#include "GLLogger.h"
#include <iostream>



namespace GLRenderer
{
    GLSLProgram::GLSLProgram(): p_vertexShader(NULL), p_fragmentShader(NULL)
    {
        m_programHandle = glCreateProgram();
        
        if (m_programHandle == 0)
        {
            Log("Unable to create program");
        }
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
        CheckError();
        
        delete p_vertexShader;
        delete p_fragmentShader;
        delete p_attributes;
    }
    
    void GLSLProgram::SetVertexShader(GLSLShader *pVertexShader)
    {
        p_vertexShader = pVertexShader;
    }
    
    void GLSLProgram::SetFragmentShader(GLSLShader *pFragmentShader)
    {
        p_fragmentShader = pFragmentShader;
    }
    
    void GLSLProgram::Use() const
    {
        glUseProgram(m_programHandle);
    }
    
    GLuint GLSLProgram::GetProgramHandle() const
    {
        return m_programHandle;
    }
    
    GLuint GLSLProgram::GetAttributesCount() const
    {
        return p_attributes->size();
    }
    
    GLSLAttribute * GLSLProgram::GetAttributeAtIndex(GLuint index) const
    {
        return p_attributes->at(index);
    }
    
    GLuint GLSLProgram::GetUniformsCount() const
    {
        return p_uniforms->size();
    }
    
    GLSLUniform * GLSLProgram::GetUniformAtIndex(GLuint index) const
    {
        return p_uniforms->at(index);
    }
    
    bool GLSLProgram::Link()
    {
        glAttachShader(m_programHandle, p_vertexShader->GetShaderHandle());
        CheckError();
        glAttachShader(m_programHandle, p_fragmentShader->GetShaderHandle());
        CheckError();
        
        glLinkProgram(m_programHandle);
        CheckError();
        
        if (!IsLinked())
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
        
        ExtractAttributes();
        ExtractUniforms();
        
        return true;
    }
    
    bool GLSLProgram::IsLinked() const
    {
        GLint linkStatus;
        glGetProgramiv(m_programHandle, GL_LINK_STATUS, &linkStatus);
        
        CheckError();
        
        return (linkStatus == GL_TRUE);
    }
    
    void GLSLProgram::Execute() const
    {
        
    }
    
    void GLSLProgram::ExtractAttributes()
    {
        GLint attributesCount;
        glGetProgramiv(m_programHandle, GL_ACTIVE_ATTRIBUTES, &attributesCount);
        CheckError();
        
        GLint maxAttributeNameLength;
        glGetProgramiv(m_programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxAttributeNameLength);
        CheckError();
        
        vector<GLSLAttribute *> *pAttributes = new vector<GLSLAttribute *>();
        
        for (GLint attributeIndex = 0; attributeIndex < attributesCount; attributeIndex++)
        {
            GLsizei attributeNameLength;
            GLint attributeSize;
            GLenum attributeType;
            GLchar *attributeName = new GLchar(maxAttributeNameLength + 1);
            
            glGetActiveAttrib(m_programHandle, attributeIndex, maxAttributeNameLength, &attributeNameLength, &attributeSize, &attributeType, attributeName);
            CheckError();
            
            GLint attributeLocation = glGetAttribLocation(m_programHandle, attributeName);
            CheckError();
            
            GLSLAttribute *pAttribute = new GLSLAttribute(attributeName, attributeType, attributeSize, attributeLocation);
            pAttributes->push_back(pAttribute);
        }
        
        SetAttributes(pAttributes);
    }
    
    void GLSLProgram::ExtractUniforms()
    {
        GLint uniformsCount;
        glGetProgramiv(m_programHandle, GL_ACTIVE_UNIFORMS, &uniformsCount);
        CheckError();
        
        GLint maxUniformNameLength;
        glGetProgramiv(m_programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformNameLength);
        CheckError();
        
        vector<GLSLUniform *> *pUniforms = new vector<GLSLUniform *>();
        
        for (GLint uniformIndex = 0; uniformIndex < uniformsCount; uniformIndex++)
        {
            GLsizei uniformNameLength;
            GLint uniformSize;
            GLenum uniformType;
            GLchar *uniformName = new GLchar(maxUniformNameLength + 1);
            
            glGetActiveUniform(m_programHandle, uniformIndex, maxUniformNameLength, &uniformNameLength, &uniformSize, &uniformType, uniformName);
            CheckError();
            
            GLint uniformLocation = glGetUniformLocation(m_programHandle, uniformName);
            CheckError();
            
            GLSLUniform *pUniform = new GLSLUniform(uniformName, uniformType, uniformSize, uniformLocation);
            pUniforms->push_back(pUniform);
        }
        
        SetUniforms(pUniforms);
    }
    
    void GLSLProgram::SetAttributes(vector<GLSLAttribute *> *pAttributes)
    {
        if (p_attributes)
        {
            delete p_attributes;
        }
        
        p_attributes = pAttributes;
    }
    
    void GLSLProgram::SetUniforms(vector<GLSLUniform *> *pUniforms)
    {
        if (p_uniforms)
        {
            delete p_uniforms;
        }
        
        p_uniforms = pUniforms;
    }
}