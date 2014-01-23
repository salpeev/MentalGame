//
//  Drawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

namespace Renderer {
    
    class Drawing {
    public:
        virtual ~Drawing();
        
        virtual void Draw() const = 0;
    };
    
    
    
    class PlainDrawing: public Drawing {
    public:
        void Draw() const;
    };
}
