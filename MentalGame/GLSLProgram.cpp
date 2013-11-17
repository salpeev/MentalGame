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
    GLSLProgram::GLSLProgram(const string &rVertexShaderSource, const string &rFragmentShaderSource): m_attributes(NULL), m_uniforms(NULL)
    {
        m_vertexShader = new GLSLShader(GLSL_SHADER_TYPE_VERTEX, rVertexShaderSource);
        m_fragmentShader = new GLSLShader(GLSL_SHADER_TYPE_FRAGMENT, rFragmentShaderSource);
        
        CreateProgram();
        Link();
    }
    
    GLSLProgram::~GLSLProgram()
    {
        Invalidate();
        
        for (map<string, GLSLAttribute *>::iterator iterator = m_attributes->begin(); iterator != m_attributes->end(); iterator++)
        {
            delete iterator->second;
        }
        
        for (map<string, GLSLUniform *>::iterator iterator = m_uniforms->begin(); iterator != m_uniforms->end(); iterator++)
        {
            delete iterator->second;
        }
        
        delete m_vertexShader;
        delete m_fragmentShader;
        delete m_attributes;
        delete m_uniforms;
    }
    
    void GLSLProgram::Use() const
    {
        glUseProgram(m_programHandle);
    }
    
    bool GLSLProgram::IsLinked() const
    {
        GLint linkStatus;
        glGetProgramiv(m_programHandle, GL_LINK_STATUS, &linkStatus);
        
        CheckError();
        
        return (linkStatus == GL_TRUE);
    }
    
    GLuint GLSLProgram::GetProgramHandle() const
    {
        return m_programHandle;
    }
    
    GLSLAttribute * GLSLProgram::GetAttributeWithName(const string &rAttributeName) const
    {
        return m_attributes->at(rAttributeName);
    }
    
    GLSLUniform * GLSLProgram::GetUniformWithName(const string &rUniformName) const
    {
        return m_uniforms->at(rUniformName);
    }
    
#pragma mark - Private Methods
    
    void GLSLProgram::CreateProgram()
    {
        m_programHandle = glCreateProgram();
        
        if (m_programHandle == 0)
        {
            Log("Unable to create program");
        }
    }
    
    bool GLSLProgram::Link()
    {
        glAttachShader(m_programHandle, m_vertexShader->GetShaderHandle());
        CheckError();
        glAttachShader(m_programHandle, m_fragmentShader->GetShaderHandle());
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
    
    void GLSLProgram::Invalidate()
    {
        if (!IsInvalidated()) {
            glDeleteProgram(m_programHandle);
            m_programHandle = 0;
            
            CheckError();
        }
    }
    
    bool GLSLProgram::IsInvalidated() const
    {
        GLint deleteStatus;
        glGetProgramiv(m_programHandle, GL_DELETE_STATUS, &deleteStatus);
        
        CheckError();
        
        return (deleteStatus == GL_TRUE);
    }
    
    void GLSLProgram::ExtractAttributes()
    {
        GLint attributesCount;
        glGetProgramiv(m_programHandle, GL_ACTIVE_ATTRIBUTES, &attributesCount);
        CheckError();
        
        GLint maxAttributeNameLength;
        glGetProgramiv(m_programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxAttributeNameLength);
        CheckError();
        
        map<string, GLSLAttribute *> *pAttributes = new map<string, GLSLAttribute *>();
        
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
            pAttributes->insert(make_pair(attributeName, pAttribute));
            
            delete [] attributeName;
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
        
        map<string, GLSLUniform *> *pUniforms = new map<string, GLSLUniform *>();
        
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
            pUniforms->insert(make_pair(uniformName, pUniform));
            
            delete [] uniformName;
        }
        
        SetUniforms(pUniforms);
    }
    
    void GLSLProgram::SetAttributes(map<string, GLRenderer::GLSLAttribute *> *pAttributes)
    {
        delete m_attributes;
        m_attributes = pAttributes;
    }
    
    void GLSLProgram::SetUniforms(map<string, GLRenderer::GLSLUniform *> *pUniforms)
    {
        delete m_uniforms;
        m_uniforms = pUniforms;
    }
}