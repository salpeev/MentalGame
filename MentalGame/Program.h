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



namespace Renderer {
    class Attribute;
    class Uniform;
    
    class Program {
    public:
        Program(const string &rVertexShaderSource, const string &rFragmentShaderSource);
        Program(const Program *program) = delete;
        ~Program();
        
        void ExecuteDrawRequest(GLSLDrawRequest *pDrawRequest) const;
        
        GLuint GetProgramHandle() const;
        
    private:
        void Create();
        void Link();
        void Use() const;
        void Delete();
        void ExtractAttributes();
        void ExtractUniforms();
        
        bool IsLinked() const;
        bool IsUsed() const;
        bool IsDeleted() const;
        
        GLuint m_programHandle;
        
        GLSLShader *m_vertexShader;
        GLSLShader *m_fragmentShader;
        
        map<string, Attribute *> *m_attributes;
        map<string, Uniform *> *m_uniforms;
    };
}