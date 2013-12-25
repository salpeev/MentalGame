//
//  Program.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLShader.h"
#include "GLSLAttribute.h"
#include "GLSLUniform.h"
#include "GLSLVertexBuffer.h"
#include <map>

using namespace std;



namespace GLRenderer
{
    
    class GLSLProgram
    {
    public:
        GLSLProgram(const string &rVertexShaderSource, const string &rFragmentShaderSource);
        GLSLProgram(const GLSLProgram *program) = delete;
        ~GLSLProgram();
        
        void Use() const;
        
        bool IsLinked() const;
        bool IsUsed() const;
        GLuint GetProgramHandle() const;
        
        map<string, GLSLAttribute *> * GetAttributes() const;
        map<string, GLSLUniform *> * GetUniforms() const;
        
        GLSLAttribute * GetAttributeByName(string attributeName) const;
        GLSLUniform * GetUniformByName(string uniformName) const;
        
    private:
        void CreateProgram();
        bool Link();
        void Invalidate();
        bool IsInvalidated() const;
        void ExtractAttributes();
        void ExtractUniforms();
        void SetAttributes(map<string, GLSLAttribute *> *pAttributes);
        void SetUniforms(map<string, GLSLUniform *> *pUniforms);
        
        GLuint m_programHandle;
        
        GLSLShader *m_vertexShader;
        GLSLShader *m_fragmentShader;
        
        map<string, GLSLAttribute *> *m_attributes;
        map<string, GLSLUniform *> *m_uniforms;
    };
    
}