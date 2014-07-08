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
    class PositionNormalInitializer;
    class CubeMapUniformInitializer;
    class DrawRequest;
    class CubeMapCamera;
    
    
    
    class GlassSphereDrawing: public DrawingLeaf {
    public:
        GlassSphereDrawing();
        ~GlassSphereDrawing();
        
        PositionModelviewModifier *GetPositionModelviewModifier() const;
        
    protected:
        void Update(float interval);
        void Draw(const Matrix4 &rProjectionMatrix, const Matrix4 &rInvertedCameraMatrix) const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        PositionNormalInitializer *m_attributeInitializer;
        CubeMapUniformInitializer *m_uniformInitializer;
        DrawRequest *m_drawRequest;
        PositionModelviewModifier *m_positionModifier;
        CubeMapCamera *m_cubeMapCamera;
    };
}
