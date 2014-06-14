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
        colorGlassDrawing->GetPositionModelviewModifier()->SetPosition(Point3(0.0f, -1.0f, -4.8f));
        GetDrawing()->AddSubDrawing(colorGlassDrawing);
        
//        SegmentDrawing *segmentDrawing = new SegmentDrawing();
//        segmentDrawing->SetStartPoint(Point3(-1.5, -1.5, -4));
//        segmentDrawing->SetEndPoint(Point3(1.5, 1.5, -5));
//        GetDrawing()->AddSubDrawing(segmentDrawing);
        
        GlassSphereDrawing *glassSphereDrawing0 = new GlassSphereDrawing();
        glassSphereDrawing0->GetPositionModelviewModifier()->SetPosition(Point3(-2.0f, -2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing0);

        GlassSphereDrawing *glassSphereDrawing1 = new GlassSphereDrawing();
        glassSphereDrawing1->GetPositionModelviewModifier()->SetPosition(Point3(2.0f, -2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing1);
        
        GlassSphereDrawing *glassSphereDrawing2 = new GlassSphereDrawing();
        glassSphereDrawing2->GetPositionModelviewModifier()->SetPosition(Point3(2.0f, 2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing2);
        
        GlassSphereDrawing *glassSphereDrawing3 = new GlassSphereDrawing();
        glassSphereDrawing3->GetPositionModelviewModifier()->SetPosition(Point3(-2.0f, 2.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing3);
        
        GlassSphereDrawing *glassSphereDrawing4 = new GlassSphereDrawing();
        glassSphereDrawing4->GetPositionModelviewModifier()->SetPosition(Point3(0.0f, 0.0f, -7));
        GetDrawing()->AddSubDrawing(glassSphereDrawing4);
        
        
        
        
        
        
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0;j < 4; j++) {
//                GlassSphereDrawing *glassSphereDrawing = new GlassSphereDrawing();
//                glassSphereDrawing->GetPositionModelviewModifier()->SetPosition(Point3(-3.0f + (2.0f * i), -3.0f + (2.0f * j), -9.0f));
//                GetDrawing()->AddSubDrawing(glassSphereDrawing);
//            }
//        }
    }
    
    GameDrawingController::~GameDrawingController() {
        
    }
}