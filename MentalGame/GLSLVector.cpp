//
//  GLSLVector.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLVector.h"



namespace GLRenderer
{
#pragma mark - GLSLVector2
    
    const float * GLSLVector2::Pointer() const
    {
        return &x;
    }
    
#pragma mark - GLSLVector3
    
    const float * GLSLVector3::Pointer() const
    {
        return &x;
    }
    
#pragma mark - GLSLVector4
    
    const float * GLSLVector4::Pointer() const
    {
        return &x;
    }
    
}
