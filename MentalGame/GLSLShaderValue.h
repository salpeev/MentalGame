//
//  GLSLShaderValue.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <string>
#include <OpenGLES/ES2/gl.h>
#include "GLSLQuaternion.h"

using namespace std;



namespace GLRenderer
{
    class GLSLProgram;
    
    
    
    class GLSLShaderValue
    {
    public:
        // TODO: Probably should be initialized only with program and location, another values can be requested
        GLSLShaderValue(GLSLProgram *pProgram, GLchar *name, GLenum type, GLint size, GLint location);
        ~GLSLShaderValue();
        
        GLSLProgram * GetProgram() const;
        string * GetName() const;
        GLenum GetType() const;
        GLint GetSize() const;
        GLint GetLocation() const;
        
    protected:
        GLSLProgram *m_program;
        string *p_name;
        GLenum m_type;
        GLint m_size;
        GLint m_location;
    };
}
