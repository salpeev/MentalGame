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

using namespace std;



namespace GLRenderer
{
    class GLSLShaderValue
    {
    public:
        GLSLShaderValue(GLchar *name, GLenum type, GLint size, GLint location);
        ~GLSLShaderValue();
        
        string *GetName() const;
        GLenum GetType() const;
        GLint GetSize() const;
        GLint GetLocation() const;
        
    protected:
        string *p_name;
        GLenum m_type;
        GLint m_size;
        GLint m_location;
    };
}
