//
//  GLSLProjectionModelviewInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLUniformInitializer.h"
#include "Matrix.h"



namespace Renderer
{
    class GLSLProjectionModelviewInitializer: public GLSLUniformInitializer
    {
    public:
        GLSLProjectionModelviewInitializer();
        ~GLSLProjectionModelviewInitializer();
        
        void SetProjectionMatrix(Matrix4 &rProjectionMatrix);
        void SetModelviewMatrix(Matrix4 &rModelviewMatix);
        
        Matrix4 & GetProjectionMatrix();
        Matrix4 & GetModelviewMatrix();
        
        void InitializeUniforms(map<string, Uniform *> *pUniforms) const;
        
    private:
        Matrix4 m_projection;
        Matrix4 m_modelview;
    };
}
