//
//  GLSLDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <string>

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    class GLSLVertexBuffer;
    
    
    
    class GLSLDrawing
    {
    public:
        GLSLDrawing();
        ~GLSLDrawing();
        
        void Initialize();
        
        void SetVertexBuffer(GLSLVertexBuffer *pVertexBuffer);
        GLSLVertexBuffer * GetVertexBuffer() const;
        
    protected:
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        
    private:
        void GenerateProgram();
        
        void SetProgram(GLSLProgram *pProgram);
        GLSLProgram * GetProgram() const;
        
        GLSLProgram *m_program;
        GLSLVertexBuffer *m_vertexBuffer;
    };
}
