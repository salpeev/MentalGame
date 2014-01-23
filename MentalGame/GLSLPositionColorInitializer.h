//
//  GLSLPositionColorInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLAttributeInitializer.h"



namespace Renderer
{
    class GLSLPositionColorInitializer: public GLSLAttributeInitializer
    {
    public:
        void InitializeAttributes(map<string, GLSLAttribute *> *pAttributes) const;
        void InitializeAttributes(map<string, GLSLAttribute *> *pAttributes, GLSLVertexArray *pVertexArray) const;
        void InitializeAttributes(map<string, GLSLAttribute *> *pAttributes, vector<GLSLVertexArray *> *pVertexArrays) const;
    };
}
