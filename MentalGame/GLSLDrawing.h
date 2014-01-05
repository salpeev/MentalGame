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
#include <vector>
#include <OpenGLES/ES2/gl.h>
#include "GLConstants.h"
#include "GLSLDrawingState.h"
#include "GLSLProgramInitializer.h"

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    class GLSLAttribute;
    class GLSLUniform;
    
    
    
    class GLSLDrawing: public GLSLProgramInitializer
    {
    public:
        GLSLDrawing();
        GLSLDrawing(const GLSLDrawing &rDrawing) = delete;
        virtual ~GLSLDrawing();
        
        void Draw() const;
        
    protected:
        GLSLAttribute * GetAttributeByName(const string &rAttributeName) const;
        GLSLUniform * GetUniformByName(const string &rUniformName) const;
        
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        
    private:
        void GenerateProgram();
        void GenerateProgramIfNeeded();
        
        void SetProgram(GLSLProgram *pProgram);
        GLSLProgram * GetProgram() const;
        
        void SetDrawingState(GLSLDrawingState *pDrawingState);
        
        GLSLProgram *m_program;
        GLSLDrawingState *m_drawingState;
    };
}
