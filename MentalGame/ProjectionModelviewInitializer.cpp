//
//  ProjectionModelviewInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ProjectionModelviewInitializer.h"
#include "Uniform.h"
#include "RenderingEngine.h"



static const char *ProjectionUniformName = "u_projection";
static const char *ModelviewUniformName = "u_modelview";



namespace Renderer {
    ProjectionModelviewInitializer::ProjectionModelviewInitializer () {
        
    }
    
    ProjectionModelviewInitializer::~ProjectionModelviewInitializer() {
        
    }
    
    void ProjectionModelviewInitializer::SetModelviewMatrix(const Matrix4 &rModelviewMatix) {
        m_modelview = rModelviewMatix;
    }
    
    void ProjectionModelviewInitializer::SetProjectionMatrix(const Matrix4 &rProjectionMatrix) {
        m_projection = rProjectionMatrix;
    }
    
    const Matrix4 & ProjectionModelviewInitializer::GetModelviewMatrix() const {
        return m_modelview;
    }
    
    void ProjectionModelviewInitializer::InitializeUniforms(map<string, Uniform *> *pUniforms) const {
        Uniform *projectionUniform = pUniforms->at(ProjectionUniformName);
        Uniform *modelviewUniform = pUniforms->at(ModelviewUniformName);
        
        projectionUniform->SetMatrix4f(m_projection);
        modelviewUniform->SetMatrix4f(m_modelview);
    }
}
