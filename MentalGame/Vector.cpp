//
//  Vector.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Vector.h"



namespace Renderer
{
#pragma mark - Vector2
    
    const float * Vector2::Pointer() const
    {
        return &x;
    }
    
#pragma mark - Vector3
    
    const float * Vector3::Pointer() const
    {
        return &x;
    }
    
#pragma mark - Vector4
    
    const float * Vector4::Pointer() const
    {
        return &x;
    }
    
}
