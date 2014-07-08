//
//  RoomDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 07.05.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingComposite.h"



namespace Renderer {
    
    class VertexBuffer;
    class IndexBuffer;
    class PositionColorInitializer;
    class ProjectionModelviewInitializer;
    class DrawRequest;
    class PositionModelviewModifier;
    class QuaternionModelviewModifier;
    
    
    
    class RoomDrawing: public DrawingComposite {
    public:
        RoomDrawing();
        ~RoomDrawing();
        
    protected:
        void Update(float interval);
        void Draw(const Matrix4 &rProjectionMatrix, const Matrix4 &rInvertedCameraMatrix) const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        PositionColorInitializer *m_attributeInitializer;
        ProjectionModelviewInitializer *m_uniformInitializer;
        DrawRequest *m_drawRequest;
        
        PositionModelviewModifier *m_positionModifier;
        QuaternionModelviewModifier *m_quaternionModifier;
    };
}
