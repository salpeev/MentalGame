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



namespace GLRenderer
{
    class GLSLAttribute;
    class GLSLVertexArray;
    
    
    
    class GLSLAttributeInitializer
    {
    public:
        GLSLAttributeInitializer(map<string, GLSLAttribute *> *pAttributes);
        
        virtual void InitializeAttributesWithCurrentBuffer() const = 0;
        virtual void InitializeAttributesWithVertexArray(GLSLVertexArray *pVertexArray) const = 0;
        virtual void InitializeAttributesWithVertexArrays(vector<GLSLVertexArray *> *pVertexArrays) const = 0;
        
    private:
        map<string, GLSLAttribute *> *m_attributes;
    };
}
