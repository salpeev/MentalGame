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
    Point::Point(): Point(0.0f, 0.0f, 0.0f) {
        
    }
    
    Point::Point(GLfloat x, GLfloat y): Point(x, y, 0.0f) {
        
    }
    
    Point::Point(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z) {
        
    }
    
    Vector3 Point::operator-(const Point &rPoint) const {
        Vector3 resultVector = Vector3(x - rPoint.x, y - rPoint.y, z - rPoint.z);
        return resultVector;
    }
    
    Point::operator Vector3() const {
        Vector3 vector(x, y, z);
        return vector;
    }
}