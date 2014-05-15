//
//  GlassSphereDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingLeaf.h"



namespace Renderer {
    
    class VertexBuffer;
    class IndexBuffer;
    class PositionModelviewModifier;
    class PositionColorInitializer;
    class ProjectionModelviewInitializer;
    class DrawRequest;
    
    
    
    class GlassSphereDrawing: public DrawingLeaf {
    public:
        GlassSphereDrawing();
        ~GlassSphereDrawing();
        
        PositionModelviewModifier *GetPositionModelviewModifier() const;
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        PositionColorInitializer *m_attributeInitializer;
        ProjectionModelviewInitializer *m_uniformInitializer;
        DrawRequest *m_drawRequest;
        
        PositionModelviewModifier *m_positionModifier;
    };
}