//
//  Program.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLShader.h"
#include "GLSLDrawRequest.h"
#include <map>

using namespace std;



namespace GLRenderer
{
    class GLSLAttribute;
    class GLSLUniform;
    
    class GLSLProgram
    {
    public:
        GLSLProgram(const string &rVertexShaderSource, const string &rFragmentShaderSource);
        GLSLProgram(const GLSLProgram *program) = delete;
        ~GLSLProgram();
        
        void ExecuteDrawRequest(GLSLDrawRequest *pDrawRequest) const;
        
        GLuint GetProgramHandle() const;
        
    private:
        void CreateProgram();
        void Link();
        void Use() const;
        void Invalidate();
        void ExtractAttributes();
        void ExtractUniforms();
        
        bool IsLinked() const;
        bool IsUsed() const;
        bool IsInvalidated() const;
        
        GLuint m_programHandle;
        
        GLSLShader *m_vertexShader;
        GLSLShader *m_fragmentShader;
        
        map<string, GLSLAttribute *> *m_attributes;
        map<string, GLSLUniform *> *m_uniforms;
    };
    
}