//
//  PlainDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Drawing.h"



namespace Renderer {
    
    class GLSLPositionColorInitializer;
    class GLSLProjectionModelviewInitializer;
    
    
    
    class ColorGlassDrawing: public Drawing {
    public:
        ColorGlassDrawing();
        ~ColorGlassDrawing();
        
        void Draw() const;
        
    private:
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLIndexBuffer *m_indexBuffer;
        GLSLPositionColorInitializer *m_attributeInitializer;
        GLSLProjectionModelviewInitializer *m_uniformInitializer;
        GLSLDrawRequest *m_drawRequest;
    };
}
