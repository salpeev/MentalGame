//
//  DrawingLeaf.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingLeaf.h"



namespace Renderer {
    
    void DrawingLeaf::UpdateHierarchy(float interval) {
        Update(interval);
    }
    
    void DrawingLeaf::DrawHierarchy() const {
        Draw();
    }
    
    void DrawingLeaf::Update(float interval) {
        
    }
    
    void DrawingLeaf::Draw() const {
        
    }
}
