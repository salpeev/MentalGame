//
//  GLSLAttribute.h
//  MentalGame
//
//  Created by Sergey Alpeev on 21.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <string>
#include <OpenGLES/ES2/gl.h>

using namespace std;



namespace GLRenderer
{
    class GLSLAttribute
    {
    public:
        GLSLAttribute(GLchar *name, GLenum type, GLint size, GLint location);
        ~GLSLAttribute();
        
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
