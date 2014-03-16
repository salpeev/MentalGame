//
//  TouchesHandler.h
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Touch.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class TouchesHandler {
    public:
        void SetNextTouchesHandler(TouchesHandler *pTouchesHandler);
        TouchesHandler * GetNextTouchesHandler() const;
        
        virtual void TouchesBegan(vector<Touch> &rTouches) const;
        virtual void TouchesMoved(vector<Touch> &rTouches) const;
        virtual void TouchesEnded(vector<Touch> &rTouches) const;
        virtual void TouchesCancelled(vector<Touch> &rTouches) const;
        
    private:
        TouchesHandler *m_nextHandler;
    };
}
