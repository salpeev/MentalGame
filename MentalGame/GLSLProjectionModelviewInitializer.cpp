//
//  GLSLProjectionModelviewInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLProjectionModelviewInitializer.h"
#include "GLSLUniform.h"



static const char *ProjectionUniformName = "u_projection";
static const char *ModelviewUniformName = "u_modelview";



namespace GLRenderer
{
    void GLSLProjectionModelviewInitializer::SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix)
    {
        m_projection = rProjectionMatrix;
    }
    
    void GLSLProjectionModelviewInitializer::SetModelviewMatrix(GLSLMatrix4 &rModelviewMatix)
    {
        m_modelview = rModelviewMatix;
    }
    
    GLSLMatrix4 GLSLProjectionModelviewInitializer::GetProjectionMatrix() const
    {
        return m_projection;
    }
    
    GLSLMatrix4 GLSLProjectionModelviewInitializer::GetModelviewMatrix() const
    {
        return m_modelview;
    }
    
    void GLSLProjectionModelviewInitializer::InitializeUniforms(map<string, GLRenderer::GLSLUniform *> *pUniforms) const
    {
        GLSLUniform *projectionUniform = pUniforms->at(ProjectionUniformName);
        GLSLUniform *modelviewUniform = pUniforms->at(ModelviewUniformName);
        
        GLSLMatrix4 projectionMatrix = GLSLMatrix4::Frustum(-2.0f, 2.0f, -2.0f, 2.0f, 4.0f, 10.0f);
        GLSLMatrix4 modelviewMatrix;
        
        projectionUniform->SetMatrix4f(projectionMatrix);
        modelviewUniform->SetMatrix4f(modelviewMatrix);
    }
}
