//
//  RenderingEngine.h
//  MentalGame
//
//  Created by Sergey Alpeev on 08.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLDrawing.h"
#include <vector>

using namespace std;



namespace GLRenderer
{
    
    class GLRenderingEngine
    {
    public:
        GLRenderingEngine(int width, int height);
        ~GLRenderingEngine();
        
        void Render() const;
        
    private:
        vector<GLSLDrawing *> *m_drawings;
    };
    
}