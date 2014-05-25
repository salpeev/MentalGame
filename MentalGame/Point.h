//
//  Point.h
//  MentalGame
//
//  Created by Sergey Alpeev on 28.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once



namespace Renderer {
    
    class Vector3;
    
    
    
    class Point2 {
    public:
        Point2();
        Point2(float x, float y);
        
        float x;
        float y;
    };
    
    
    
    class Point3 {
    public:
        Point3();
        Point3(const Point2 &rPoint);
        Point3(float x, float y);
        Point3(float x, float y, float z);
        
        Vector3 operator-(const Point3 &rPoint) const;
        Point3 operator-() const;
        operator Vector3() const;
        
        float x;
        float y;
        float z;
    };
}
