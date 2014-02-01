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
        void BindDrawApple() const;
        void BindReadApple() const;
        void DiscardReadApple() const;
        
        static void ResolveMultisampleApple();
        
    private:
        bool IsBoundDrawApple() const;
        bool IsBoundReadApple() const;
    };
}