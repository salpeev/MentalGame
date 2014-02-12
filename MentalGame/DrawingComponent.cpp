//
//  DrawingComponent.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingComponent.h"
#include "CompositeDrawing.h"



namespace Renderer {
    
    void DrawingComponent::RemoveFromParentDrawing() {
        m_parentDrawing->RemoveSubDrawing(this);
    }
    
    void DrawingComponent::SetParentDrawing(CompositeDrawing *pDrawing) {
        m_parentDrawing = pDrawing;
    }
    
    CompositeDrawing * DrawingComponent::GetParentDrawing() const {
        return m_parentDrawing;
    }
}
