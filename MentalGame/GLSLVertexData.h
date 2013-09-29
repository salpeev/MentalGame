//
//  GLSLVertexData.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include <vector>
#include "GLPoint.h"
#include "GLColor.h"
#include "GLVector.h"
#include "GLSLVertex.h"

using namespace std;



namespace GLRenderer
{
    class GLSLVertexData
    {
    public:
        GLSLVertexData();
        ~GLSLVertexData();
        
        void AddPoint(GLPoint point) const;
        void AddColor(GLColor point) const;
        void AddVertex1P1C(GLSLVertex1P1C vertex) const;
        
        GLvoid * GetDataPointer() const;
        GLsizeiptr GetDataCount() const;
        
    private:
        vector<GLfloat> *m_data;
    };
}