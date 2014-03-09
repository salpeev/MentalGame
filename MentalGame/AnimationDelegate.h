//
//  AnimationDelegate.h
//  MentalGame
//
//  Created by Sergey Alpeev on 08.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"
#include "Quaternion.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class Animation;
    
    
    
    class AnimationDelegate {
    public:
        AnimationDelegate();
        virtual ~AnimationDelegate();
        
        void AddAnimation(Animation *pAnimation);
        void UpdateAnimations(float interval);
        
        virtual Point GetPosition() const;
        virtual float GetXRotation() const;
        virtual float GetYRotation() const;
        virtual float GetZRotation() const;
        virtual Quaternion GetQuaternion() const;
        
        virtual void SetPosition(const Point &rPosition);
        virtual void SetXRotation(float angle);
        virtual void SetYRotation(float angle);
        virtual void SetZRotation(float angle);
        virtual void SetQuaternion(const Quaternion &rQuaternion);
        
    private:
        vector<Animation *> *m_animations;
    };
}
