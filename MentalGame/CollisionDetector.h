//
//  CollisionDetector.h
//  MentalGame
//
//  Created by Sergey Alpeev on 14.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"
#include "Polyhedron.h"



namespace Renderer {
    
    class CollisionDetector {
    public:
        static bool IntersectSegmentPolyhedron(Point &rA, Point &rB, Polyhedron &rPolyhedron, float &tStart, float &tEnd);
    };
}

