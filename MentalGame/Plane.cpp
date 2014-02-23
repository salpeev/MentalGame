//
//  Plane.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Plane.h"
#include "GLLogger.h"



namespace Renderer {
    
    Plane::Plane(const Point &a, const Point &b, const Point &c) {
        Vector3 ab = b - a;
        Vector3 ac = c - a;
        
        m_normal = ab.Cross(ac);
        m_normal.Normalize();
        
        m_distance = m_normal.Dot(a);
    }
    
    Plane Plane::Transformed(Matrix4 &rMatrix) const {
        Plane transformedPlane(*this);
        transformedPlane.Transform(rMatrix);
        return transformedPlane;
    }
    
    void Plane::Transform(Matrix4 &rMatrix) {
        // TODO: Cleanup this code
        // TODO: This step can be optimized if matrix contains only rotation and translation. Inverse-transpose can be omitted
//        Matrix4 invertedMatrix;
//        rMatrix.Inverted(&invertedMatrix);
//        Matrix4 resultMatrix = invertedMatrix.Transposed();
        
        Point position = GetPosition();
        
        Vector4 normal4(m_normal);
        normal4.w = 0.0f;
        normal4 = normal4 * rMatrix;
        m_normal = Vector3(normal4.x, normal4.y, normal4.z);
        m_normal.Normalize();
        
        
        Vector4 vector4(position.x, position.y, position.z, 1.0f);
        Vector4 transformedVector4 = vector4 * rMatrix;
        Vector3 transformedVector3(transformedVector4.x, transformedVector4.y, transformedVector4.z);
        
        m_distance = transformedVector3.Dot(m_normal);
    }
    
    const Vector3 & Plane::GetNormal() const {
        return m_normal;
    }
    
    float Plane::GetDistance() const {
        return m_distance;
    }
    
    Point Plane::GetPosition() const {
        Point position = m_normal * m_distance;
        return position;
    }
}
