//
//  GLSLProjectionModelviewInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLUniformInitializer.h"
#include "GLSLMatrix.h"



namespace Renderer
{
    class GLSLProjectionModelviewInitializer: public GLSLUniformInitializer
    {
    public:
        GLSLProjectionModelviewInitializer();
        ~GLSLProjectionModelviewInitializer();
        
        void SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix);
        void SetModelviewMatrix(GLSLMatrix4 &rModelviewMatix);
        
        GLSLMatrix4 & GetProjectionMatrix();
        GLSLMatrix4 & GetModelviewMatrix();
        
        void InitializeUniforms(map<string, GLSLUniform *> *pUniforms) const;
        
    private:
        GLSLMatrix4 m_projection;
        GLSLMatrix4 m_modelview;
    };
}
