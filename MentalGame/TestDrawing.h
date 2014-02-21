//
//  LineDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 21.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingLeaf.h"



namespace Renderer {
    
    class GLSLPositionColorInitializer;
    class GLSLProjectionModelviewInitializer;
    class GLSLVertexBuffer;
    class GLSLDrawRequest;
    
    
    
    class TestDrawing: public DrawingLeaf {
    public:
        TestDrawing();
        ~TestDrawing();
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        GLSLPositionColorInitializer *m_attributeInitializer;
        GLSLProjectionModelviewInitializer *m_uniformInitializer;
        GLSLVertexBuffer *m_vertexBuffer;
        GLSLDrawRequest *m_drawRequest;
    };
}
