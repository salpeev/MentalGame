//
//  ProjectionModelviewInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "UniformInitializer.h"
#include "Matrix.h"



namespace Renderer {
    class ProjectionModelviewInitializer: public UniformInitializer {
    public:
        void SetModelviewMatrix(const Matrix4 &rModelviewMatix);
        void SetProjectionMatrix(const Matrix4 &rProjectionMatrix);
        
        const Matrix4 & GetModelviewMatrix() const;
        
        void InitializeUniforms(map<string, Uniform *> *pUniforms) const;
        
    private:
        Matrix4 m_modelview;
        Matrix4 m_projection;
    };
}
