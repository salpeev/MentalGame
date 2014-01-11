//
//  GLSLUniformInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include <vector>
#include <map>

using namespace std;



namespace GLRenderer
{
    class GLSLUniform;
    
    
    
    class GLSLUniformInitializer
    {
    public:
        GLSLUniformInitializer(map<string, GLSLUniform *> *pUniforms);
        
        virtual void InitializeUniforms() const;
        
    private:
        map<string, GLSLUniform *> *m_uniforms;
    };
}

