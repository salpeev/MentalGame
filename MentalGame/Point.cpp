//
//  Point.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Point.h"
#include "Vector.h"



namespace Renderer {
    
    Point2::Point2(): Point2(0.0f, 0.0f) {
        
    }
    
    Point2::Point2(float x, float y): x(x), y(y) {
        
    }
    
    
    
    
    Point3::Point3(): Point3(0.0f, 0.0f, 0.0f) {
        
    }
    
    Point3::Point3(const Point2 &rPoint): Point3(rPoint.x, rPoint.y, 0.0f) {
        
    }
    
    Point3::Point3(float x, float y): Point3(x, y, 0.0f) {
        
    }
    
    Point3::Point3(float x, float y, float z): x(x), y(y), z(z) {
        
    }
    
    Vector3 Point3::operator-(const Point3 &rPoint) const {
        Vector3 resultVector = Vector3(x - rPoint.x, y - rPoint.y, z - rPoint.z);
        return resultVector;
    }
    
    Point3::operator Vector3() const {
        Vector3 vector(x, y, z);
        return vector;
    }
}