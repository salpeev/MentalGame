//
//  GLSLAttributeInitializer.h
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



namespace Renderer
{
    class GLSLAttribute;
    class GLSLVertexArray;
    
    
    
    class GLSLAttributeInitializer
    {
    public:
        virtual ~GLSLAttributeInitializer();
        
        virtual void InitializeAttributes(map<string, GLSLAttribute *> *pAttributes) const = 0;
        virtual void InitializeAttributes(map<string, GLSLAttribute *> *pAttributes, GLSLVertexArray *pVertexArray) const = 0;
        virtual void InitializeAttributes(map<string, GLSLAttribute *> *pAttributes, vector<GLSLVertexArray *> *pVertexArrays) const = 0;
    };
}
