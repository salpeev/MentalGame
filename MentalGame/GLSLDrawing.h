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
#include "GLSLAttributeInitializer.h"
#include "GLSLUniformInitializer.h"

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    class GLSLAttribute;
    class GLSLUniform;
    
    
    
    class GLSLDrawing: GLSLProgramInitializer
    {
    public:
        GLSLDrawing();
        GLSLDrawing(const GLSLDrawing &rDrawing) = delete;
        virtual ~GLSLDrawing();
        
        void SetAttributeInitializer(GLSLAttributeInitializer *pAttributeinitializer);
        void SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer);
        void SetDrawingState(GLSLDrawingState *pDrawingState);
        
        GLSLAttributeInitializer * GetAttributeInitializer() const;
        GLSLUniformInitializer * GetUniformInitializer() const;
        GLSLDrawingState * GetDrawingState() const;
        
        void Draw() const;
        
        void InitializeAttributes() const;
        void InitializeAttributes(GLSLVertexArray *pVertexArray) const;
        void InitializeAttributes(vector<GLSLVertexArray *> *pVertexArrays) const;
        void InitializeUniforms() const;
        
    protected:
        // TODO: Move to interface?
        virtual string VertexShaderSource() const = 0;
        virtual string FragmentShaderSource() const = 0;
        
    private:
        void GenerateProgram();
        void GenerateProgramIfNeeded();
        
        GLSLProgram *m_program;
        GLSLAttributeInitializer *m_attributeInitializer;
        GLSLUniformInitializer *m_uniformInitializer;
        GLSLDrawingState *m_drawingState;
    };
}
