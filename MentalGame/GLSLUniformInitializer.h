//
//  GLSLUniformInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include <map>

using namespace std;



namespace Renderer
{
    class GLSLUniform;
    
    
    
    class GLSLUniformInitializer
    {
    public:
        virtual ~GLSLUniformInitializer();
        
        virtual void InitializeUniforms(map<string, GLSLUniform *> *pUniforms) const = 0;
    };
}

