//
//  IDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once



namespace Renderer {
    
    class IDrawing {
    public:
        IDrawing();
        IDrawing(const IDrawing &rDrawing) = delete;
        virtual ~IDrawing();
        
        virtual void Draw() const = 0;
    };
}
