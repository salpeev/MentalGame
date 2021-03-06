//
//  Polyhedron.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 14.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Polyhedron.h"



namespace Renderer {
    
    Polyhedron::Polyhedron(const vector<Plane> &rPlanes): m_planes(rPlanes) {
        
    }
    
    Polyhedron::~Polyhedron() {
        
    }
    
    Polyhedron Polyhedron::Transformed(Matrix4 &rMatrix, bool translatedRotatedOnly) const {
        Polyhedron transformedPolyhedron(*this);
        transformedPolyhedron.Transform(rMatrix, translatedRotatedOnly);
        return transformedPolyhedron;
    }
    
    void Polyhedron::Transform(Matrix4 &rMatrix, bool translatedRotatedOnly) {
        for (int planeIndex = 0; planeIndex < m_planes.size(); planeIndex++) {
            Plane plane = m_planes[planeIndex];
            plane.Transform(rMatrix, translatedRotatedOnly);
            m_planes[planeIndex] = plane;
        }
    }
    
    const vector<Plane> & Polyhedron::GetPlanes() const {
        return m_planes;
    }
}
