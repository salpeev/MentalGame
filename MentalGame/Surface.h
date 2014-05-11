//
//  Surface.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <vector>

using namespace std;



namespace Renderer {
    
    enum VERTEX_ATTRIBUTE {
        VERTEX_ATTRIBUTE_COLOR = 1 << 0,
        VERTEX_ATTRIBUTE_NORMAL = 1 << 1
    };
    
    
    
    class Surface {
    public:
        virtual ~Surface() {}
        
        virtual int GetVertexCount() const = 0;
        virtual int GetLineIndexCount() const = 0;
        virtual int GetTriangleIndexCount() const = 0;
        
        virtual void GenerateVertices(vector<float> &vertices, unsigned int flags = 0) const = 0;
        virtual void GenerateLineIndices(vector<unsigned short> &indices) = 0;
        virtual void GenerateTriangleIndices(vector<unsigned short> &indices) = 0;
    };
}
