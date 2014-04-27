//
//  PlainDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingComposite.h"
#include "PositionModelviewModifier.h"
#include "QuaternionModelviewModifier.h"
#include "ScaleModelviewModifier.h"



namespace Renderer {
    
    class VertexBuffer;
    class IndexBuffer;
    class PositionColorInitializer;
    class ProjectionModelviewInitializer;
    class DrawRequest;
    class Polyhedron;
    
    
    
    class ColorGlassDrawing: public DrawingComposite {
    public:
        ColorGlassDrawing();
        ~ColorGlassDrawing();
        
        bool PointInside(const Point &rPoint) const;
        
        PositionModelviewModifier *GetPositionModelviewModifier() const;
        QuaternionModelviewModifier *GetQuaternionModelviewModifier() const;
        
        void TouchesBegan(vector<Touch *> &rTouches) const;
        void TouchesMoved(vector<Touch *> &rTouches) const;
        void TouchesEnded(vector<Touch *> &rTouches) const;
        void TouchesCancelled(vector<Touch *> &rTouches) const;
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        PositionColorInitializer*m_attributeInitializer;
        ProjectionModelviewInitializer *m_uniformInitializer;
        DrawRequest *m_drawRequest;
        Polyhedron *m_shape;
        
        PositionModelviewModifier *m_positionModifier;
        QuaternionModelviewModifier *m_quaternionModifier;
        ScaleModelviewModifier *m_scaleModifier;
    };
}
