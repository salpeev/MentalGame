//
//  Logger.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLLogger.h"
#include <iostream>
#include <OpenGLES/ES2/gl.h>

using namespace std;



namespace GLRenderer
{
    void Log(const char *formatString, ...)
    {
        va_list params;
        char buf[BUFSIZ];
        
        va_start(params, formatString);
        vsprintf(buf, formatString, params);
        
        printf("%s\n", buf);
        
        va_end(params);
    }
    
    bool CheckError()
    {
        GLenum errorType = glGetError();
        switch (errorType) {
            case GL_NO_ERROR: return false;
            case GL_INVALID_ENUM: cout << "ERROR: Invalid enum" << endl; break;
            case GL_INVALID_OPERATION: cout << "ERROR: Invalid operation" << endl; break;
            case GL_INVALID_VALUE: cout << "ERROR: Invalid value" << endl; break;
            case GL_OUT_OF_MEMORY: cout << "ERROR: Out of memory" << endl; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: cout << "ERROR: Invalid framebuffer operation" << endl; break;
            default: cout << "ERROR: Unknown error" << endl; break;
        }
        
        return true;
    }
}