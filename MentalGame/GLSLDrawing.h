//
//  GLSLDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <string>
#include <OpenGLES/ES2/gl.h>
#include "GLSLDrawRequest.h"

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    class GLSLAttribute;
    class GLSLUniform;
    
    
    
    class GLSLDrawing
    {
    public:
        GLSLDrawing();
        GLSLDrawing(const GLSLDrawing &rDrawing) = delete;
        virtual ~GLSLDrawing();
        
        void ExecuteDrawRequest(GLSLDrawRequest *pDrawRequest) const;
        
    protected:
        // TODO: Move to interface?
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        
    private:
        void GenerateProgram();
        void GenerateProgramIfNeeded();
        
        GLSLProgram *m_program;
    };
}
