//
//  ShaderValue.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "ShaderValue.h"



namespace Renderer {
    
    ShaderValue::ShaderValue(Program *pProgram, GLchar *name, GLenum type, GLint size, GLint location): m_program(pProgram), m_type(type), m_size(size), m_location(location) {
        p_name = new string(name);
    }
    
    Program * ShaderValue::GetProgram() const {
        return m_program;
    }
    
    ShaderValue::~ShaderValue() {
        delete p_name;
    }
    
    string *ShaderValue::GetName() const {
        return p_name;
    }
    
    GLenum ShaderValue::GetType() const {
        return m_type;
    }
    
    GLint ShaderValue::GetSize() const {
        return m_size;
    }
    
    GLint ShaderValue::GetLocation() const {
        return m_location;
    }
}