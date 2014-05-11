//
//  ParametricSurfaces.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Surface.h"
#include "Point.h"



namespace Renderer {
    
    class ParametricSurface {
    public:
        ParametricSurface(int xDivisions, int yDivisions, float xUpperBound, float yUpperBound);
        ~ParametricSurface();
        
        int GetVertexCount() const;
        int GetLineIndexCount() const;
        int GetTriangleIndexCount() const;
        
        void GenerateVertices(vector<float> &vertices, unsigned int flags) const;
        void GenerateLineIndices(vector<unsigned short> &indices);
        void GenerateTriangleIndices(vector<unsigned short> &indices);
        
    protected:
        virtual Point Evaluate(const Point &domain) const = 0;
        virtual bool InvertNormal(const Point &domain) const;
        
    private:
        Point ComputeDomain(float x, float y) const;
        
        int m_xDivisions;
        int m_yDivisions;
        int m_xSlices;
        int m_ySlices;
        float m_xUpperBound;
        float m_yUpperBound;
    };
}
