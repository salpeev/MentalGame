//
//  GLSLAttributeInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 05.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include <vector>

using namespace std;



namespace GLRenderer
{
    class GLSLVertexArray;
    
    
    
    class GLSLProgramInitializer
    {
    public:
        virtual void InitializeAttributesWithCurrentBuffer() const = 0;
        virtual void InitializeAttributesWithVertexArray(GLSLVertexArray *pVertexArray) const = 0;
        virtual void InitializeAttributesWithVertexArrays(vector<GLSLVertexArray *> *pVertexArrays) const = 0;
        virtual void InitializeUniforms() const;
    };
}
