//
//  MultisampleFramebuffer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 30.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "Framebuffer.h"



namespace Renderer {
    
    class MultisampleFramebuffer: public Framebuffer {
    public:
        bool IsBoundRead() const;
        bool IsBoundDraw() const;
        void BindRead() const;
        void BindDraw() const;
        void Resolve() const;
        void Discard() const;
    };
}