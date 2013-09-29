//
//  ResourceManager.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <string>

using namespace std;



namespace GLRenderer
{
    class GLResourceManager
    {
    public:
        static const GLResourceManager & SharedInstance()
        {
            static GLResourceManager resourceManager;
            return resourceManager;
        }
        
        string LoadTextFileNamed(const string &fileName) const;
        
    private:
        GLResourceManager(){}
        GLResourceManager(const GLResourceManager &resourceManager);
        GLResourceManager & operator= (const GLResourceManager &);
    };
}

