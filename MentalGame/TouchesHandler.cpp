//
//  TouchesHandler.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "TouchesHandler.h"



namespace Renderer {
    
    void TouchesHandler::SetNextTouchesHandler(TouchesHandler *pTouchesHandler) {
        m_nextHandler = pTouchesHandler;
    }
    
    TouchesHandler * TouchesHandler::GetNextTouchesHandler() const {
        return m_nextHandler;
    }
    
    void TouchesHandler::TouchesBegan(vector<Touch> &rTouches) const {
        m_nextHandler->TouchesBegan(rTouches);
    }
    
    void TouchesHandler::TouchesMoved(vector<Touch> &rTouches) const {
        m_nextHandler->TouchesMoved(rTouches);
    }
    
    void TouchesHandler::TouchesEnded(vector<Touch> &rTouches) const {
        m_nextHandler->TouchesEnded(rTouches);
    }
    
    void TouchesHandler::TouchesCancelled(vector<Touch> &rTouches) const {
        m_nextHandler->TouchesCancelled(rTouches);
    }
}
