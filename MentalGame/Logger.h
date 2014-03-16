//
//  Logger.h
//  MentalGame
//
//  Created by Sergey Alpeev on 11.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once



namespace Renderer {
    
    void Log(const char *formatString, ...);
    bool CheckError();
}
