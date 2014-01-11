//
//  GLSLProjectionModelviewInitializer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLUniformInitializer.h"



namespace GLRenderer
{
    class GLSLProjectionModelviewInitializer: public GLSLUniformInitializer
    {
    public:
        void InitializeUniforms() const;
    };
}
