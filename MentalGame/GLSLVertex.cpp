//
//  GLSLVertex.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVertex.h"
#include "GLConstants.h"



namespace Renderer
{
    GLSLVertex1P::GLSLVertex1P(): GLSLVertex1P(GLPoint())
    {
        
    }
    
    GLSLVertex1P::GLSLVertex1P(GLPoint position): m_position(position)
    {
        
    }
    
    
    
    GLSLVertex1C::GLSLVertex1C(): GLSLVertex1C(GLColor())
    {
        
    }
    
    GLSLVertex1C::GLSLVertex1C(GLColor color): m_color(color)
    {
        
    }
    
    
    
    GLSLVertex1P1C::GLSLVertex1P1C(): GLSLVertex1P1C(GLPoint(), GLColor())
    {
        
    }
    
    GLSLVertex1P1C::GLSLVertex1P1C(GLPoint position, GLColor color): m_position(position), m_color(color)
    {
        
    }
}

