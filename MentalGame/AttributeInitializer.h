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



namespace Renderer {
    class Attribute;
    class VertexArray;
    
    
    
    class GLSLAttributeInitializer {
    public:
        virtual ~GLSLAttributeInitializer();
        
        virtual void InitializeAttributes(map<string, Attribute *> *pAttributes) const = 0;
        virtual void InitializeAttributes(map<string, Attribute *> *pAttributes, VertexArray *pVertexArray) const = 0;
        virtual void InitializeAttributes(map<string, Attribute *> *pAttributes, vector<VertexArray *> *pVertexArrays) const = 0;
    };
}
