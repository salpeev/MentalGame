//
//  PlainDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "CompositeDrawing.h"



namespace Renderer {
    
    class VertexBuffer;
    class IndexBuffer;
    class GLSLPositionColorInitializer;
    class GLSLProjectionModelviewInitializer;
    class GLSLDrawRequest;
    class Polyhedron;
    
    
    
    class ColorGlassDrawing: public CompositeDrawing {
    public:
        ColorGlassDrawing();
        ~ColorGlassDrawing();
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        GLSLPositionColorInitializer *m_attributeInitializer;
        GLSLProjectionModelviewInitializer *m_uniformInitializer;
        GLSLDrawRequest *m_drawRequest;
        Polyhedron *m_shape;
    };
}
