//
//  PlainDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "CompositeDrawing.h"



namespace Renderer {
    
    class GLSLVertexBuffer;
    class GLSLIndexBuffer;
    class GLSLPositionColorInitializer;
    class GLSLProjectionModelviewInitializer;
    class GLSLDrawRequest;
    
    
    
    class ColorGlassDrawing: public CompositeDrawing {
    public:
        ColorGlassDrawing();
        ~ColorGlassDrawing();
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
        GLSLPositionColorInitializer *m_attributeInitializer;
        GLSLProjectionModelviewInitializer *m_uniformInitializer;
        GLSLDrawRequest *m_drawRequest;
    };
}
