//
//  GLSLProgramInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 12.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <vector>

using namespace std;



namespace GLRenderer
{
    class GLSLVertexArray;
    
    class GLSLProgramInitializer
    {
    public:
        virtual void InitializeAttributes() const = 0;
        virtual void InitializeAttributes(GLSLVertexArray *pVertexArray) const = 0;
        virtual void InitializeAttributes(vector<GLSLVertexArray *> *pVertexArrays) const = 0;
        virtual void InitializeUniforms() const = 0;
    };
}
