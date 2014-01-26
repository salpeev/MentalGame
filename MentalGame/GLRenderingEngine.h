//
//  RenderingEngine.h
//  MentalGame
//
//  Created by Sergey Alpeev on 08.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <vector>

using namespace std;



namespace Renderer
{
    class Drawing;
    
    
    
    class GLRenderingEngine
    {
    public:
        GLRenderingEngine(int width, int height);
        ~GLRenderingEngine();
        
        void Render() const;
        
    private:
        void Test0() const;
        void Test1() const;
        void Test2() const;
        void Test3() const;
        void Test4() const;
        void Test5() const;
        void Test6() const;
        void Test7() const;
        void Test8() const;
        void Test9() const;
        void Test10() const;
        void Test11() const;
        void Test12() const;
        void Test13() const;
        
        vector<Drawing *> *m_drawings;
    };
    
}