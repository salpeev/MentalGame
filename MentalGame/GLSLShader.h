//
//  GLSLShader.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include <string>
#include "GLConstants.h"

using namespace std;



namespace Renderer
{
    class GLSLShader
    {
    public:
        GLSLShader(GLSL_SHADER_TYPE type, const string &rSource);
        GLSLShader(const GLSLShader &shader) = delete;
        ~GLSLShader();
        
        GLuint GetShaderHandle() const;
        
        bool IsCompiled() const;
        
    private:
        void SetType(GLSL_SHADER_TYPE type);
        void SetSource(const string &source);
        
        void Compile() const;
        void Delete();
        
        bool IsDeleted() const;
        
        GLuint m_shaderHandle;
    };
}
