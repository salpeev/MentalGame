//
//  Vertex.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"
#include "Color.h"



namespace Renderer {
    
    class Vertex1P {
    public:
        Vertex1P();
        Vertex1P(Point position);
        
        Point m_position;
    };
    
    
    
    class Vertex1C {
    public:
        Vertex1C();
        Vertex1C(Color color);
        
        Color m_color;
    };
    
    
    
    class Vertex1P1C {
    public:
        Vertex1P1C();
        Vertex1P1C(Point position, Color color);
        
        Point m_position;
        Color m_color;
    };
    
    
    
    class Vertex1P1T {
    public:
        Vertex1P1T();
        Vertex1P1T(Point position, Point textureCoordinate);
        
        Point m_position;
        Point m_textureCoordinate;
    };
}
