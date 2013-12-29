//
//  GLSLUniform.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLUniform.h"
#include "GLLogger.h"
#include "GLSLProgram.h"



namespace GLRenderer
{
    GLSLUniform::GLSLUniform(GLSLProgram *pProgram, GLchar *name, GLenum type, GLint size, GLint location): GLSLShaderValue(pProgram, name, type, size, location)
    {
        
    }
    
    void GLSLUniform::SetMatrix4(const GLSLMatrix4 &rMatrix) const
    {
        glUniformMatrix4fv(m_location, m_size, GLSL_FALSE, rMatrix.Pointer());
        CheckError();
    }
    
    GLSLMatrix4 GLSLUniform::GetMatrix4() const
    {
        GLSLMatrix4 matrix;
        
        glGetUniformfv(GetProgram()->GetProgramHandle(), m_location, (GLfloat *)matrix.Pointer());
        CheckError();
        
        return matrix;
    }
}