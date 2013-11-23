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
    public:
        GLSLPositionColorDrawing();
        ~GLSLPositionColorDrawing();
        
    private:
        string VertexShaderSource() const;
        string FragmentShaderSource() const;
        void InitializeAttributes(const map<string, GLSLAttribute *> *pAttributes) const;
    };
}
