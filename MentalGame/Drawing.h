//
//  Drawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawRequest.h"



namespace Renderer {
    
    class GLSLProgram;
    
    
    
    class Drawing {
    public:
        Drawing();
        Drawing(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        Drawing(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        Drawing(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        Drawing(GLSLVertexBuffer *pVertexBuffer);
        Drawing(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer);
        Drawing(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices);
        Drawing(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices);
        Drawing(GLSLVertexArray &rVertexArray);
        Drawing(vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer);
        Drawing(vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices);
        Drawing(vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices);
        Drawing(vector<GLSLVertexArray *> &rVertexArrays);
        Drawing(const Drawing &rDrawing) = delete;
        virtual ~Drawing();
        
        void UseData(GLSLVertexBuffer *pVertexBuffer, GLSLIndexBuffer *pIndexBuffer);
        void UseData(GLSLVertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        void UseData(GLSLVertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        void UseData(GLSLVertexBuffer *pVertexBuffer);
        void UseData(GLSLVertexArray &rVertexArray, GLSLIndexBuffer *pIndexBuffer);
        void UseData(GLSLVertexArray &rVertexArray, vector<GLushort> &rIndices);
        void UseData(GLSLVertexArray &rVertexArray, vector<GLubyte> &rIndices);
        void UseData(GLSLVertexArray &rVertexArray);
        void UseData(vector<GLSLVertexArray *> &rVertexArrays, GLSLIndexBuffer *pIndexBuffer);
        void UseData(vector<GLSLVertexArray *> &rVertexArrays, vector<GLushort> &rIndices);
        void UseData(vector<GLSLVertexArray *> &rVertexArrays, vector<GLubyte> &rIndices);
        void UseData(vector<GLSLVertexArray *> &rVertexArrays);
        
        void Draw() const;
        
    protected:
        void SetProgram(GLSLProgram *program);
        void SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer);
        void SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer);
        
        GLSLProgram *GetProgram() const;
        GLSLAttributeInitializer *GetAttributeInitializer() const;
        GLSLUniformInitializer *GetUniformInitializer() const;
        
    private:
        GLSLDrawRequest *m_drawRequest;
        GLSLProgram *m_program;
        GLSLAttributeInitializer *m_attributeInitializer;
        GLSLUniformInitializer *m_uniformInitializer;
    };
}
