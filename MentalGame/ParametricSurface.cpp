//
//  ParametricSurfaces.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ParametricSurface.h"
#include "Color.h"
#include "Vector.h"



namespace Renderer {
    
    ParametricSurface::ParametricSurface(int xDivisions, int yDivisions, float xUpperBound, float yUpperBound): m_xDivisions(xDivisions), m_yDivisions(yDivisions), m_xSlices(xDivisions - 1.0f), m_ySlices(yDivisions - 1.0f), m_xUpperBound(xUpperBound), m_yUpperBound(yUpperBound) {
        
    }
    
    int ParametricSurface::GetVertexCount() const {
        int vertexCount = m_xDivisions * m_yDivisions;
        return vertexCount;
    }
    
    int ParametricSurface::GetLineIndexCount() const {
        int lineIndexCount = 4.0f * m_xSlices * m_ySlices;
        return lineIndexCount;
        
    }
    
    int ParametricSurface::GetTriangleIndexCount() const {
        int triangleIndexCount = 6.0f * m_xSlices * m_ySlices;
        return triangleIndexCount;
    }
    
    void ParametricSurface::GenerateVertices(vector<float> &vertices, unsigned int flags) const {
        int floatsPerVertex = 3;
        if (flags & VERTEX_ATTRIBUTE_COLOR) {
            floatsPerVertex += 4;
        }
        if (flags & VERTEX_ATTRIBUTE_NORMAL) {
            floatsPerVertex += 3;
        }
        
        int floatsCount = GetVertexCount() * floatsPerVertex;
        vertices.resize(floatsCount);
        float *attribute = &vertices[0];
        
        for (int j = 0; j < m_yDivisions; j++) {
            for (int i = 0; i < m_xDivisions; i++) {
                Point domain = ComputeDomain(i, j);
                Point range = Evaluate(domain);
                
                Point *pPosition = (Point *)attribute;
                *pPosition++ = range;
                attribute = (float *)pPosition;
                
                if (flags & VERTEX_ATTRIBUTE_COLOR) {
                    Color *pColor = (Color *)attribute;
                    *pColor++ = Color(1.0f, 0.0f, 0.0f);
                    attribute = (float *)pColor;
                }
                
                if (flags & VERTEX_ATTRIBUTE_NORMAL) {
                    float s = (float)i;
                    float t = (float)j;
                    
                    // Nudge the point if the normal is indeterminate
                    if (i == 0) {
                        s += 0.01f;
                    }
                    if (i == m_xSlices) {
                        s -= 0.01f;
                    }
                    if (j == 0) {
                        t += 0.01f;
                    }
                    if (j == m_ySlices) {
                        t -= 0.01f;
                    }
                    
                    // Compute the tangents and their cross product
                    Vector3 p = Evaluate(ComputeDomain(s, t));
                    Vector3 u = Evaluate(ComputeDomain(s + 0.01f, t)) - p;
                    Vector3 v = Evaluate(ComputeDomain(s, t + 0.01f)) - p;
                    Vector3 normal = u.Cross(v).Normalized();
                    
                    if (InvertNormal(domain)) {
                        normal = -normal;
                    }
                    
                    Vector3 *pNormal = (Vector3 *)attribute;
                    *pNormal++ = normal;
                    attribute = (float *)pNormal;
                }
            }
        }
    }
    
    void ParametricSurface::GenerateLineIndices(vector<unsigned short> &indices) {
        indices.resize(GetLineIndexCount());
        vector<unsigned short>::iterator index = indices.begin();
        
        for (int j = 0, vertex = 0; j < m_ySlices; j++) {
            for (int i = 0; i < m_xSlices; i++) {
                int next = (i + 1) % m_xDivisions;
                *index++ = vertex + i;
                *index++ = vertex + next;
                *index++ = vertex + i;
                *index++ = vertex + i + m_xDivisions;
            }
            
            vertex += m_xDivisions;
        }
    }
    
    void ParametricSurface::GenerateTriangleIndices(vector<unsigned short> &indices) {
        indices.resize(GetTriangleIndexCount());
        vector<unsigned short>::iterator index = indices.begin();
        
        for (int j = 0, vertex = 0; j < m_xSlices; j++) {
            for (int i = 0; i < m_ySlices; i++) {
                int next = (i + 1) % m_xDivisions;
                *index++ = vertex + i;
                *index++ = vertex + next;
                *index++ = vertex + i + m_xDivisions;
                *index++ = vertex + next;
                *index++ = vertex + next + m_xDivisions;
                *index++ = vertex + i + m_xDivisions;
            }
            
            vertex += m_xDivisions;
        }
    }
    
    Point ParametricSurface::ComputeDomain(float x, float y) const {
        float xDomain = x * m_xUpperBound / m_xSlices;
        float yDomain = y * m_yUpperBound / m_ySlices;
        return Point(xDomain, yDomain);
    }
    
    bool ParametricSurface::InvertNormal(const Point &domain) const {
        return false;
    }
}