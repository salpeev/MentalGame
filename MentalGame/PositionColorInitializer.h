//
//  PositionColorInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "AttributeInitializer.h"



namespace Renderer {
    class PositionColorInitializer: public GLSLAttributeInitializer {
    public:
        void InitializeAttributes(map<string, Attribute *> *pAttributes) const;
        void InitializeAttributes(map<string, Attribute *> *pAttributes, GLSLVertexArray *pVertexArray) const;
        void InitializeAttributes(map<string, Attribute *> *pAttributes, vector<GLSLVertexArray *> *pVertexArrays) const;
    };
}
