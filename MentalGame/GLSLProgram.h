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
        GLSLProgram();
        GLSLProgram(GLSLShader *pVertexShader, GLSLShader *pFragmentShader);
        ~GLSLProgram();
        
        void SetVertexShader(GLSLShader *pVertexShader);
        void SetFragmentShader(GLSLShader *pFragmentShader);
        void Use() const;
        
        GLuint GetProgramHandle() const;
        
        GLuint GetAttributesCount() const;
        GLSLAttribute * GetAttributeAtIndex(GLuint index) const;
        
        void SetVertexBuffer(GLSLVertexBuffer *pVertexBuffer);
        GLSLVertexBuffer * GetVertexBuffer() const;
        
        bool Link();
        bool IsLinked() const;
        
    private:
        void ExtractAttributes();
        void ExtractUniforms();
        void SetAttributes(vector<GLSLAttribute *> *pAttributes);
        void SetUniforms(vector<GLSLUniform *> *pUniforms);
        
        GLuint m_programHandle;
        
        GLSLShader *p_vertexShader;
        GLSLShader *p_fragmentShader;
        
        vector<GLSLAttribute *> *p_attributes;
        vector<GLSLUniform *> *p_uniforms;
        
        GLSLVertexBuffer *p_vertexBuffer;
    };
    
}