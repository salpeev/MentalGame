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



namespace Renderer
{
    GLSLProjectionModelviewInitializer::GLSLProjectionModelviewInitializer () {
        m_projection = GLSLMatrix4::Frustum(-2.0f, 2.0f, -2.0f, 2.0f, 4.0f, 10.0f);
    }
    
    GLSLProjectionModelviewInitializer::~GLSLProjectionModelviewInitializer() {
        
    }
    
    void GLSLProjectionModelviewInitializer::SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix) {
        m_projection = rProjectionMatrix;
    }
    
    void GLSLProjectionModelviewInitializer::SetModelviewMatrix(GLSLMatrix4 &rModelviewMatix) {
        m_modelview = rModelviewMatix;
    }
    
    GLSLMatrix4 & GLSLProjectionModelviewInitializer::GetProjectionMatrix() {
        return m_projection;
    }
    
    GLSLMatrix4 & GLSLProjectionModelviewInitializer::GetModelviewMatrix() {
        return m_modelview;
    }
    
    void GLSLProjectionModelviewInitializer::InitializeUniforms(map<string, GLSLUniform *> *pUniforms) const {
        GLSLUniform *projectionUniform = pUniforms->at(ProjectionUniformName);
        GLSLUniform *modelviewUniform = pUniforms->at(ModelviewUniformName);
        
        projectionUniform->SetMatrix4f(m_projection);
        modelviewUniform->SetMatrix4f(m_modelview);
    }
}
