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
    class ProjectionModelviewInitializer;
    class DrawRequest;
    class CubeMapCamera;
    
    
    
    enum class GlassSphereDrawingMode: short {
        GlassSphereDrawingModeDefault,
        GlassSphereDrawingModeFrontNormals,
        GlassSphereDrawingModeBackNormals,
        GlassSphereDrawingModeDepth
    };
    
    
    
    class GlassSphereDrawing: public DrawingLeaf {
    public:
        GlassSphereDrawing();
        ~GlassSphereDrawing();
        
        void Draw(const Matrix4 &rProjectionMatrix) const;
        
        PositionModelviewModifier *GetPositionModelviewModifier() const;
        
        void SetDrawingMode(GlassSphereDrawingMode mode);
        GlassSphereDrawingMode GetDrawingMode() const;
        
    protected:
        void Update(float interval);
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        PositionNormalInitializer *m_attributeInitializer;
        CubeMapUniformInitializer *m_cubemapUniformInitializer;
        ProjectionModelviewInitializer *m_projectionModelviewInitializer;
        DrawRequest *m_drawRequest;
        PositionModelviewModifier *m_positionModifier;
        CubeMapCamera *m_cubeMapCamera;
        GlassSphereDrawingMode m_drawingMode;
    };
}
