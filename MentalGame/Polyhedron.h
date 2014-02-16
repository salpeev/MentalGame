//
//  Polyhedron.h
//  MentalGame
//
//  Created by Sergey Alpeev on 14.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <vector>
#include "Plane.h"

using namespace std;



namespace Renderer {
    
    class Polyhedron {
    public:
        Polyhedron(const vector<Plane> &rPlanes);
        ~Polyhedron();
        
        const vector<Plane> & GetPlanes() const;
        
    private:
        vector<Plane> m_planes;
    };
}
