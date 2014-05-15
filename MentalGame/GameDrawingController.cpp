//
//  GameDrawingController.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GameDrawingController.h"
#include "TextureDrawing.h"
#include "ColorGlassDrawing.h"
#include "SegmentDrawing.h"
#include "ResourceManager.h"
#include "RoomDrawing.h"
#include "GlassSphereDrawing.h"



namespace Renderer {
    
    GameDrawingController::GameDrawingController() {
        // TODO: Memory management
        RoomDrawing *roomDrawing = new RoomDrawing();
        GetDrawing()->AddSubDrawing(roomDrawing);
        
//        TextureDrawing *textureDrawing = new TextureDrawing();
//        GetDrawing()->AddSubDrawing(textureDrawing);
        
        ColorGlassDrawing *colorGlassDrawing = new ColorGlassDrawing();
        colorGlassDrawing->GetPositionModelviewModifier()->SetPosition(Point3(0.0f, 0.0f, -5.5f));
        GetDrawing()->AddSubDrawing(colorGlassDrawing);
        
//        SegmentDrawing *segmentDrawing = new SegmentDrawing();
//        segmentDrawing->SetStartPoint(Point3(-1.5, -1.5, -4));
//        segmentDrawing->SetEndPoint(Point3(1.5, 1.5, -5));
//        GetDrawing()->AddSubDrawing(segmentDrawing);
        
        GlassSphereDrawing *glassSphereDrawing = new GlassSphereDrawing();
        glassSphereDrawing->GetPositionModelviewModifier()->SetPosition(Point3(0.0f, 2.0f, -5.5f));
        GetDrawing()->AddSubDrawing(glassSphereDrawing);
    }
    
    GameDrawingController::~GameDrawingController() {
        
    }
}