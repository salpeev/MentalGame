//
//  Program.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLShader.h"



namespace Renderer
{
    
    class GLSLProgram
    {
    public:
        GLSLProgram();
        GLSLProgram(GLSLShader *pVertexShader, GLSLShader *pFragmentShader);
        ~GLSLProgram();
        
        void SetVertexShader(GLSLShader *pVertexShader);
        void SetFragmentShader(GLSLShader *pFragmentShader);
        void Activate() const;
        
        GLuint GetProgramHandle() const;
        
        bool Link() const;
        bool IsLinked() const;
        
    private:
        GLuint m_programHandle;
        
        GLSLShader *p_vertexShader;
        GLSLShader *p_fragmentShader;
    };
    
}