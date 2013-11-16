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
#include <vector>

using namespace std;



namespace GLRenderer
{
    
    class GLSLProgram
    {
    public:
        GLSLProgram(GLSLShader &rVertexShader, GLSLShader &rFragmentShader);
        ~GLSLProgram();
        
        void Use() const;
        void Invalidate();
        
        bool IsLinked() const;
        GLuint GetProgramHandle() const;
        
        GLuint GetAttributesCount() const;
        GLSLAttribute * GetAttributeAtIndex(GLuint index) const;
        
        GLuint GetUniformsCount() const;
        GLSLUniform * GetUniformAtIndex(GLuint index) const;
        
    private:
        void CreateProgram();
        bool Link();
        void ExtractAttributes();
        void ExtractUniforms();
        void SetAttributes(vector<GLSLAttribute *> *pAttributes);
        void SetUniforms(vector<GLSLUniform *> *pUniforms);
        
        GLuint m_programHandle;
        
        GLSLShader *m_vertexShader;
        GLSLShader *m_fragmentShader;
        
        vector<GLSLAttribute *> *m_attributes;
        vector<GLSLUniform *> *m_uniforms;
    };
    
}