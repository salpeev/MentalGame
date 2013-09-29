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

using namespace std;



namespace GLRenderer
{
    class GLSLVertexData
    {
    public:
        GLSLVertexData();
        ~GLSLVertexData();
        
        void AddPoint2(GLPoint2 point) const;
        void AddPoint3(GLPoint3 point) const;
        void AddColor(GLColor point) const;
        
        GLvoid * GetDataPointer() const;
        GLsizeiptr GetDataCount() const;
        
    private:
        vector<GLfloat> *m_data;
    };
}