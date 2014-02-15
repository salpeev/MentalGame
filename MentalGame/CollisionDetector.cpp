//
//  CollisionDetector.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 14.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "CollisionDetector.h"



namespace Renderer {
    
    bool CollisionDetector::IntersectSegmentPolyhedron(Point &rA, Point &rB, Polyhedron &rPolyhedron, float &tStart, float &tEnd) {
        // Compute direction vector for the segment
        Vector3 directionVector = rB - rA;
        
        // Set initial interval to being the whole segment. For a ray, tEnd should be set to +FLT_MAX. For a line, additionaly tStart should be set to -FLT_MAX
        tStart = 0.0f;
        tEnd = 1.0f;
        
        // Intersect segment against each plane
        const vector<Plane> &planes = rPolyhedron.GetPlanes();
        for (int i = 0; i < planes.size(); i++) {
            Plane plane = planes.at(i);          // TODO: Is reference improves performance? Probably not
            float denominator = plane.GetNormal().Dot(directionVector);
            float distance = plane.GetDistance() - plane.GetNormal().Dot(rA);
            
            // Test if segment runs parallel to the plane
            if (denominator == 0.0f) {
                // If so, return "no intersection" if segment lies outside plane
                if (distance > 0.0f) {
                    return false;
                }
            } else {
                // Compute parametrized t value for intersection with current plane
                float t = distance / denominator;
                if (denominator < 0.0f) {
                    // When entering halfstapce, update tStart if t is larger
                    if (t > tStart) {
                        tStart = t;
                    }
                } else {
                    // When exiting halfspace, update tEnd if t is smaller
                    if (t < tEnd) {
                        tEnd = t;
                    }
                }
                
                // Exit with "no intersection" if intersection becomes empty
                if (tStart > tEnd) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
