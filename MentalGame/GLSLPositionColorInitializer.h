//
//  GLSLPositionColorInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLAttributeInitializer.h"



namespace GLRenderer
{
    class GLSLPositionColorInitializer: public GLSLAttributeInitializer
    {
    public:
        void InitializeAttributesWithCurrentBuffer() const;
        void InitializeAttributesWithVertexArray(GLSLVertexArray *pVertexArray) const;
        void InitializeAttributesWithVertexArrays(vector<GLSLVertexArray *> *pVertexArrays) const;
    };
}
