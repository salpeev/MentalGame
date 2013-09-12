//
//  GLSLShader.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include <string>

using namespace std;



namespace Renderer
{
    class GLSLShader
    {
    public:
        GLSLShader();
        GLSLShader(GLenum type, const string *source);
        ~GLSLShader();
        
        void SetType(GLenum type);
        void SetSource(const string *source);
        
        GLuint GetShaderHandle() const;
        
        bool Compile() const;
        bool IsCompiled() const;
        
    private:
        GLuint m_shaderHandle;
    };
}
