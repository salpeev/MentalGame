//
//  GLSLUniform.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>



namespace Renderer
{
    class GLSLUniform
    {
    public:
        GLSLUniform(GLchar *name, GLenum type, GLint size, GLint location);
        ~GLSLUniform();
        
        GLchar *GetName() const;
        GLenum GetType() const;
        GLint GetSize() const;
        GLint GetLocation() const;
        
    private:
        GLchar *m_name;
        GLenum m_type;
        GLint m_size;
        GLint m_location;
    };
}
