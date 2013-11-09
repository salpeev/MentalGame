//
//  GLSLDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

namespace GLRenderer
{
    class GLSLProgram;
    class GLSLVertexBuffer;
    
    
    
    class GLSLDrawing
    {
    public:
        GLSLDrawing();
        ~GLSLDrawing();
        
    protected:
        virtual void LoadProgram() = 0;
        
        void SetProgram(GLSLProgram *pProgram);
        GLSLProgram * GetProgram() const;
        
        void SetVertexBuffer(GLSLVertexBuffer *pVertexBuffer);
        GLSLVertexBuffer * GetVertexBuffer() const;
        
    private:
        GLSLProgram *m_program;
        GLSLVertexBuffer *m_vertexBuffer;
    };
}
