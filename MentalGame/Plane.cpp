//
//  Plane.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Plane.h"
#include "Logger.h"



namespace Renderer {
    
    Plane::Plane(const Point3 &a, const Point3 &b, const Point3 &c) {
        Vector3 ab = b - a;
        Vector3 ac = c - a;
        
        m_normal = ab.Cross(ac);
        m_normal.Normalize();
        
        m_distance = m_normal.Dot(a);
    }
    
    Plane Plane::Transformed(Matrix4 &rMatrix, bool translatedRotatedOnly) const {
        Plane transformedPlane(*this);
        transformedPlane.Transform(rMatrix, translatedRotatedOnly);
        return transformedPlane;
    }
    
    void Plane::Transform(Matrix4 &rMatrix, bool translatedRotatedOnly) {
        Point3 position = GetPosition();
        
        // Transform normal
        Matrix4 normalMatrix(rMatrix);
        if (!translatedRotatedOnly) {
            Matrix4 invertedMatrix;
            if (rMatrix.Inverted(&invertedMatrix)) {
                normalMatrix = invertedMatrix.Transposed();
            }
        }
        
        Vector4 normal4(m_normal, 0.0f);
        normal4 = normal4 * normalMatrix;
        m_normal = Vector3(normal4.x, normal4.y, normal4.z);
        m_normal.Normalize();
        
        // Transform distance
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
    
    Point3 Plane::GetPosition() const {
        Point3 position = m_normal * m_distance;
        return position;
    }
}










/*
 http://stackoverflow.com/questions/7685495/transforming-a-3d-plane-by-4x4-matrix
 
 You need to convert your plane to a different representation. One where N is the normal, and O is any point on the plane. The normal you already know, it's your (xyz). A point on the plane is also easy, it's your normal N times your distance d.
 
 Transform O by the 4x4 matrix in the normal way, this becomes your new O. You will need a Vector4 to multiply with a 4x4 matrix, set the W component to 1 (x, y, z, 1).
 
 Also transform N by the 4x4 matrix, but set the W component to 0 (x, y, z, 0). Setting the W component to 0 means that your normals won't get translated. If your matrix is composed of more that just translating and rotating, then this step isn't so simple. Instead of multiplying by your transformation matrix, you have to multiply by the transpose of the inverse of the matrix i.e. Matrix4.Transpose(Matrix4.Invert(Transform)), there's a good explanation on why here.
 
 You now have a new normal vector N and a new position vector O. However I suppose you want it in xyzd form again? No problem. As before, xyz is your normal N all that's left is to calculate d. d is the distance of the plane from the origin, along the normal vector. Hence, it is simply the dot product of O and N.
 
 */