//
//  Matrix4Animation.h
//  MentalGame
//
//  Created by Sergey Alpeev on 01.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Animation.h"
#include "Matrix.h"



namespace Renderer {
    
    class Matrix4Animation: public Animation {
    public:
        
    private:
        Matrix4 m_initialMatrix;
    };
}
