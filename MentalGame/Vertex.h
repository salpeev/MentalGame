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
#include "Vector.h"



namespace Renderer {
    
    class Vertex1P {
    public:
        Vertex1P();
        Vertex1P(Point3 position);
        
        Point3 m_position;
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
        Vertex1P1C(Point3 position, Color color);
        
        Point3 m_position;
        Color m_color;
    };
    
    
    
    class Vertex1P1T {
    public:
        Vertex1P1T();
        Vertex1P1T(Point3 position, Point2 textureCoordinate);
        
        Point3 m_position;
        Point2 m_textureCoordinate;
    };
    
    
    
    class Vertex1P1N {
    public:
        Vertex1P1N();
        Vertex1P1N(Point3 position, Vector3 normal);
        
        Point3 m_position;
        Vector3 m_normal;
    };
}
