//
//  GLSLProjectionModelviewInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLProjectionModelviewInitializer.h"
#include "Uniform.h"
#include "RenderingEngine.h"



static const char *ProjectionUniformName = "u_projection";
static const char *ModelviewUniformName = "u_modelview";



namespace Renderer
{
    GLSLProjectionModelviewInitializer::GLSLProjectionModelviewInitializer () {
        CSize windowSize = RenderingEngine::SharedInstance().GetWindowSize();
        GLfloat screenAspectRatio = windowSize.width / windowSize.height;
        
        m_projection = Matrix4::Frustum(-2.0f, 2.0f, -2.0f / screenAspectRatio, 2.0f / screenAspectRatio, 4.0f, 10.0f);
    }
    
    GLSLProjectionModelviewInitializer::~GLSLProjectionModelviewInitializer() {
        
    }
    
    void GLSLProjectionModelviewInitializer::SetProjectionMatrix(Matrix4 &rProjectionMatrix) {
        m_projection = rProjectionMatrix;
    }
    
    void GLSLProjectionModelviewInitializer::SetModelviewMatrix(Matrix4 &rModelviewMatix) {
        m_modelview = rModelviewMatix;
    }
    
    Matrix4 & GLSLProjectionModelviewInitializer::GetProjectionMatrix() {
        return m_projection;
    }
    
    Matrix4 & GLSLProjectionModelviewInitializer::GetModelviewMatrix() {
        return m_modelview;
    }
    
    void GLSLProjectionModelviewInitializer::InitializeUniforms(map<string, Uniform *> *pUniforms) const {
        Uniform *projectionUniform = pUniforms->at(ProjectionUniformName);
        Uniform *modelviewUniform = pUniforms->at(ModelviewUniformName);
        
        projectionUniform->SetMatrix4f(m_projection);
        modelviewUniform->SetMatrix4f(m_modelview);
    }
}
