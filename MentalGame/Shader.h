//
//  Shader.h
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



namespace Renderer {
    
    class Shader {
    public:
        Shader(GLSL_SHADER_TYPE type, const string &rSource);
        Shader(const Shader &shader) = delete;
        ~Shader();
        
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
