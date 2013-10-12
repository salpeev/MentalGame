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
#include "GLSLVertex.h"

using namespace std;



namespace GLRenderer
{
    class GLSLVertexData
    {
    public:
        GLSLVertexData();
        ~GLSLVertexData();
        
        virtual void AddVertex(GLSLVertex *pVertex) const = 0;
        
        GLvoid * GetDataPointer() const;
        GLsizeiptr GetDataCount() const;
        
    protected:
        void AddValue(GLfloat value) const;
        
    private:
        vector<GLfloat> *m_data;
    };
    
    
    
    class GLSLVertexData1P: public GLSLVertexData
    {
    public:
        void AddVertex(GLSLVertex *pVertex) const;
    };
    
    
    
    class GLSLVertexData1C: public GLSLVertexData
    {
    public:
        void AddVertex(GLSLVertex *pVertex) const;
    };
    
    
    
    class GLSLVertexData1P1C: public GLSLVertexData
    {
    public:
        void AddVertex(GLSLVertex *pVertex) const;
    };
}