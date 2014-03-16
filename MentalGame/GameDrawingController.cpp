//
//  GameDrawingController.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GameDrawingController.h"
#include "ColorGlassDrawing.h"
#include "SegmentDrawing.h"



namespace Renderer {
    
    GameDrawingController::GameDrawingController() {
        // TODO: Memory management
        ColorGlassDrawing *colorGlassDrawing = new ColorGlassDrawing();
        colorGlassDrawing->SetPosition(Point(0.0f, 0.0f, -5.5f));
        GetDrawing()->AddSubDrawing(colorGlassDrawing);
        
        SegmentDrawing *segmentDrawing = new SegmentDrawing();
        segmentDrawing->SetStartPoint(Point(-1.5, -1.5, -4));
        segmentDrawing->SetEndPoint(Point(1.5, 1.5, -5));
        GetDrawing()->AddSubDrawing(segmentDrawing);
    }
    
    GameDrawingController::~GameDrawingController() {
        
    }
}