//
//  Vertex.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Vertex.h"
#include "Constants.h"



namespace Renderer {
    
    Vertex1P::Vertex1P(): Vertex1P(Point3()) {
        
    }
    
    Vertex1P::Vertex1P(Point3 position): m_position(position) {
        
    }
    
    
    
    Vertex1C::Vertex1C(): Vertex1C(Color()) {
        
    }
    
    Vertex1C::Vertex1C(Color color): m_color(color) {
        
    }
    
    
    
    Vertex1P1C::Vertex1P1C(): Vertex1P1C(Point3(), Color()) {
        
    }
    
    Vertex1P1C::Vertex1P1C(Point3 position, Color color): m_position(position), m_color(color) {
        
    }
    
    
    
    Vertex1P1T::Vertex1P1T(): Vertex1P1T(Point3(), Point2()) {
        
    }
    
    Vertex1P1T::Vertex1P1T(Point3 position, Point2 textureCoordinate): m_position(position), m_textureCoordinate(textureCoordinate) {
        
    }
}

