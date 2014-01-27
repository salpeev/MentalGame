//
//  ShaderValue.h
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



namespace Renderer
{
    class Program;
    
    
    
    class ShaderValue {
    public:
        // TODO: Probably should be initialized only with program and location, another values can be requested
        // TODO: Replace type with enum
        ShaderValue(Program *pProgram, GLchar *name, GLenum type, GLint size, GLint location);
        ~ShaderValue();
        
        Program * GetProgram() const;
        string * GetName() const;
        GLenum GetType() const;
        GLint GetSize() const;
        GLint GetLocation() const;
        
    private:
        Program *m_program;
        string *p_name;
        GLenum m_type;
        GLint m_size;
        GLint m_location;
    };
}
