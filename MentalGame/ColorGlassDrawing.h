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
    class PositionColorInitializer;
    class ProjectionModelviewInitializer;
    class GLSLDrawRequest;
    class Polyhedron;
    
    
    
    class ColorGlassDrawing: public CompositeDrawing {
    public:
        ColorGlassDrawing();
        ~ColorGlassDrawing();
        
        // Animation delegate
        Point GetPosition() const;
        float GetXRotation() const;
        float GetYRotation() const;
        float GetZRotation() const;
        Quaternion GetQuaternion() const;
        
        void SetPosition(const Point &rPosition);
        void SetXRotation(float angle);
        void SetYRotation(float angle);
        void SetZRotation(float angle);
        void SetQuaternion(const Quaternion &rQuaternion);
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        PositionColorInitializer*m_attributeInitializer;
        ProjectionModelviewInitializer *m_uniformInitializer;
        GLSLDrawRequest *m_drawRequest;
        Polyhedron *m_shape;
        
        Point m_position;
        Quaternion m_quaternion;
    };
}
