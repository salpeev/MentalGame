//
//  LineDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 21.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingLeaf.h"
#include "Color.h"



namespace Renderer {
    
    class PositionColorInitializer;
    class ProjectionModelviewInitializer;
    class VertexBuffer;
    class DrawRequest;
    
    
    
    class SegmentDrawing: public DrawingLeaf {
    public:
        SegmentDrawing();
        ~SegmentDrawing();
        
        void SetStartPoint(const Point &rStart);
        void SetEndPoint(const Point &rEnd);
        void SetStartColor(const Color &rStartColor);
        void SetEndColor(const Color &rEndColor);
        
        Point GetStartPoint() const;
        Point GetEndPoint() const;
        Color GetStartColor() const;
        Color GetEndColor() const;
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        PositionColorInitializer*m_attributeInitializer;
        ProjectionModelviewInitializer *m_uniformInitializer;
        VertexBuffer *m_vertexBuffer;
        DrawRequest *m_drawRequest;
        
        Point m_start;
        Point m_end;
        Color m_startColor;
        Color m_endColor;
    };
}
