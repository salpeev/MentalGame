//
//  Program.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Program.h"
#include "GLConstants.h"
#include "Logger.h"
#include "Attribute.h"
#include "Uniform.h"
#include <iostream>



namespace Renderer {
    
    Program::Program(const string &rVertexShaderSource, const string &rFragmentShaderSource): m_attributes(NULL), m_uniforms(NULL) {
        m_vertexShader = new Shader(GLSL_SHADER_TYPE_VERTEX, rVertexShaderSource);
        m_fragmentShader = new Shader(GLSL_SHADER_TYPE_FRAGMENT, rFragmentShaderSource);
        
        Create();
        Link();
    }
    
    Program::~Program() {
        Delete();
        
        for (map<string, Attribute *>::iterator iterator = m_attributes->begin(); iterator != m_attributes->end(); iterator++) {
            delete iterator->second;
        }
        
        for (map<string, Uniform *>::iterator iterator = m_uniforms->begin(); iterator != m_uniforms->end(); iterator++) {
            delete iterator->second;
        }
        
        delete m_vertexShader;
        delete m_fragmentShader;
        delete m_attributes;
        delete m_uniforms;
    }
    
#pragma mark - Public Mehods
    
    void Program::ExecuteDrawRequest(GLSLDrawRequest *pDrawRequest) const {
        Use();
        pDrawRequest->Draw(m_attributes, m_uniforms);
    }
    
    GLuint Program::GetProgramHandle() const {
        return m_programHandle;
    }
    
#pragma mark - Private Methods
    
    void Program::Create() {
        m_programHandle = glCreateProgram();
        
        if (m_programHandle == 0)
        {
            Log("Unable to create program");
        }
    }
    
    void Program::Link() {
        glAttachShader(m_programHandle, m_vertexShader->GetShaderHandle());
        CheckError();
        glAttachShader(m_programHandle, m_fragmentShader->GetShaderHandle());
        CheckError();
        
        glLinkProgram(m_programHandle);
        CheckError();
        
        if (!IsLinked()) {
            GLint infoLength;
            glGetProgramiv(m_programHandle, GLSL_PROGRAM_IV_INFO_LOG_LENGTH, &infoLength);
            
            if (infoLength > 1) {
                char *infoLog = (char *)malloc(sizeof(char) * infoLength);
                
                glGetProgramInfoLog(m_programHandle, infoLength, NULL, infoLog);
                Log("PROGRAM: %s", infoLog);
                
                free(infoLog);
            }
            
            return;
        }
        
        ExtractAttributes();
        ExtractUniforms();
    }
    
    void Program::Use() const {
        if (!IsUsed()) {
            glUseProgram(m_programHandle);
            CheckError();
        }
    }
    
    void Program::Delete() {
        if (!IsDeleted()) {
            glDeleteProgram(m_programHandle);
            m_programHandle = 0;
            
            CheckError();
        }
    }
    
    void Program::ExtractAttributes() {
        GLint attributesCount;
        glGetProgramiv(m_programHandle, GLSL_PROGRAM_IV_ACTIVE_ATTRIBUTES, &attributesCount);
        CheckError();
        
        GLint maxAttributeNameLength;
        glGetProgramiv(m_programHandle, GLSL_PROGRAM_IV_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxAttributeNameLength);
        CheckError();
        
        map<string, Attribute *> *pAttributes = new map<string, Attribute *>();
        
        for (GLint attributeIndex = 0; attributeIndex < attributesCount; attributeIndex++) {
            GLsizei attributeNameLength;
            GLint attributeSize;
            GLenum attributeType;
            GLchar *attributeName = new GLchar(maxAttributeNameLength + 1);
            
            glGetActiveAttrib(m_programHandle, attributeIndex, maxAttributeNameLength, &attributeNameLength, &attributeSize, &attributeType, attributeName);
            CheckError();
            
            GLint attributeLocation = glGetAttribLocation(m_programHandle, attributeName);
            CheckError();
            
            GLSL_DATA_TYPE type = (GLSL_DATA_TYPE)attributeType;
            Attribute *pAttribute = new Attribute(this, attributeName, type, attributeSize, attributeLocation);
            pAttributes->insert(make_pair(attributeName, pAttribute));
            
            delete attributeName;
        }
        
        m_attributes = pAttributes;
    }
    
    void Program::ExtractUniforms()
    {
        GLint uniformsCount;
        glGetProgramiv(m_programHandle, GLSL_PROGRAM_IV_ACTIVE_UNIFORMS, &uniformsCount);
        CheckError();
        
        GLint maxUniformNameLength;
        glGetProgramiv(m_programHandle, GLSL_PROGRAM_IV_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformNameLength);
        CheckError();
        
        map<string, Uniform *> *pUniforms = new map<string, Uniform *>();
        
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
            
            Uniform *pUniform = new Uniform(this, uniformName, (GLSL_DATA_TYPE)uniformType, uniformSize, uniformLocation);
            pUniforms->insert(make_pair(uniformName, pUniform));
            
            delete uniformName;
        }
        
        m_uniforms = pUniforms;
    }
    
    bool Program::IsLinked() const
    {
        GLint linkStatus;
        glGetProgramiv(m_programHandle, GLSL_PROGRAM_IV_LINK_STATUS, &linkStatus);
        CheckError();
        
        return (linkStatus == GLSL_TRUE);
    }
    
    bool Program::IsUsed() const
    {
        GLint currentProgramHandle;
        glGetIntegerv(GET_PARAMETER_CURRENT_PROGRAM, &currentProgramHandle);
        CheckError();
        
        bool used = (currentProgramHandle == m_programHandle);
        return used;
    }
    
    bool Program::IsDeleted() const
    {
        GLint deleteStatus;
        glGetProgramiv(m_programHandle, GLSL_PROGRAM_IV_DELETE_STATUS, &deleteStatus);
        
        CheckError();
        
        return (deleteStatus == GLSL_TRUE);
    }
}