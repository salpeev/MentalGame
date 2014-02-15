//
//  Polyhedron.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 14.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Polyhedron.h"



namespace Renderer {
    
    Polyhedron::Polyhedron(vector<Plane> &rPlanes): m_planes(rPlanes) {
        
    }
    
    Polyhedron::~Polyhedron() {
        
    }
    
    const vector<Plane> & Polyhedron::GetPlanes() const {
        return m_planes;
    }
}
