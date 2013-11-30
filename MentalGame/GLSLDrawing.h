//
//  GLSLDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <string>
#include <map>

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    class GLSLAttribute;
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    
    
    
    class GLSLDrawing
    {
    public:
        GLSLDrawing();
        virtual ~GLSLDrawing();
        
        void Initialize();
        void Draw() const;
        
        void UseVertexAndIndexBuffers(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        void UseVertexBuffer(GLSLVertexBuffer *pVertexBuffer);
        // TODO: Need to think about that
//        void UseRawData(???);
        
    protected:
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        virtual void InitializeAttributes(const map<string, GLSLAttribute *> *pAttributes) const = 0;
        
    private:
        void GenerateProgram();
        
        void SetProgram(GLSLProgram *pProgram);
        GLSLProgram * GetProgram() const;
        
        GLSLProgram *m_program;
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
    };
}
