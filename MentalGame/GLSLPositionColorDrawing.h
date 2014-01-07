//
//  GLSLPositionColorDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawing.h"



namespace GLRenderer
{
    class GLSLPositionColorDrawing: public GLSLDrawing
    {
    private:
        string VertexShaderSource() const;
        string FragmentShaderSource() const;
        
        void InitializeAttributesWithCurrentBuffer() const;
        void InitializeAttributesWithVertexArray(GLSLVertexArray *pVertexArray) const;
        void InitializeAttributesWithVertexArrays(vector<GLSLVertexArray *> *pVertexArrays) const;
        void InitializeUniforms() const;
    };
}
