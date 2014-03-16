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
    GLSLVertex1P::GLSLVertex1P(): GLSLVertex1P(Point())
    {
        
    }
    
    GLSLVertex1P::GLSLVertex1P(Point position): m_position(position)
    {
        
    }
    
    
    
    GLSLVertex1C::GLSLVertex1C(): GLSLVertex1C(Color())
    {
        
    }
    
    GLSLVertex1C::GLSLVertex1C(Color color): m_color(color)
    {
        
    }
    
    
    
    GLSLVertex1P1C::GLSLVertex1P1C(): GLSLVertex1P1C(Point(), Color())
    {
        
    }
    
    GLSLVertex1P1C::GLSLVertex1P1C(Point position, Color color): m_position(position), m_color(color)
    {
        
    }
}

