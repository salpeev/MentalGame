//
//  CubeMapUniformInitializer.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 07.06.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "CubeMapUniformInitializer.h"



static const char *ProjectionUniformName = "u_projection";
static const char *ModelviewUniformName = "u_modelview";
static const char *NormalMatrixUniformName = "u_normalMatrix";
static const char *CameraPositionUniformName = "u_cameraPosition";



namespace Renderer {
    
    void CubeMapUniformInitializer::SetProjectionMatrix(const Matrix4 &rProjectionMatrix) {
        m_projection = rProjectionMatrix;
    }
    
    void CubeMapUniformInitializer::SetModelviewMatrix(const Matrix4 &rModelviewMatix) {
        m_modelview = rModelviewMatix;
    }
    
    void CubeMapUniformInitializer::SetNormalMatrix(const Matrix3 &rNormalMatrix) {
        m_normalMatrix = rNormalMatrix;
    }
    
    void CubeMapUniformInitializer::SetCameraPosition(const Point3 &rCameraPosition) {
        m_cameraPosition = rCameraPosition;
    }
    
    void CubeMapUniformInitializer::InitializeUniforms(map<string, Uniform *> *pUniforms) const {
        Uniform *projectionUniform = pUniforms->at(ProjectionUniformName);
        Uniform *modelviewUniform = pUniforms->at(ModelviewUniformName);
        Uniform *normalMatrixUniform = pUniforms->at(NormalMatrixUniformName);
        Uniform *cameraPositionUniform = pUniforms->at(CameraPositionUniformName);
        
        projectionUniform->SetMatrix4f(m_projection);
        modelviewUniform->SetMatrix4f(m_modelview);
        normalMatrixUniform->SetMatrix3f(m_normalMatrix);
        cameraPositionUniform->Set3f(m_cameraPosition.x, m_cameraPosition.y, m_cameraPosition.z);
    }
}
