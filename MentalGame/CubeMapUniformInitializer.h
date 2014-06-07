//
//  CubeMapUniformInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 07.06.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "UniformInitializer.h"
#include "Matrix.h"



namespace Renderer {
    
    class CubeMapUniformInitializer: public UniformInitializer {
    public:
        void SetProjectionMatrix(const Matrix4 &rProjectionMatrix);
        void SetModelviewMatrix(const Matrix4 &rModelviewMatix);
        void SetNormalMatrix(const Matrix3 &rNormalMatrix);
        void SetCameraPosition(const Point3 &rCameraPosition);
        
        void InitializeUniforms(map<string, Uniform *> *pUniforms) const;
        
    private:
        Matrix4 m_projection;
        Matrix4 m_modelview;
        Matrix3 m_normalMatrix;
        Point3 m_cameraPosition;
    };
}