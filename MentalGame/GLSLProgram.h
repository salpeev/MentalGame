//
//  Program.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLShader.h"
#include "GLSLAttribute.h"
#include "GLSLUniform.h"
#include <vector>

using namespace std;



namespace Renderer
{
    
    class GLSLProgram
    {
    public:
        GLSLProgram();
        GLSLProgram(GLSLShader *pVertexShader, GLSLShader *pFragmentShader);
        ~GLSLProgram();
        
        void SetVertexShader(GLSLShader *pVertexShader);
        void SetFragmentShader(GLSLShader *pFragmentShader);
        void Activate() const;
        
        GLuint GetProgramHandle() const;
        
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
    };
    
}