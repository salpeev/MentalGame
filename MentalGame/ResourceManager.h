//
//  ResourceManager.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "TextureInfo.h"
#include <string>

using namespace std;



namespace Renderer {
    
    class ResourceManager {
    public:
        static const ResourceManager & SharedInstance() {
            static ResourceManager resourceManager;
            return resourceManager;
        }
        
        string LoadTextFileNamed(const string &fileName) const;
        TextureInfo * LoadTexturePOT(const string &fileName) const;
        
    private:
        ResourceManager();
        ResourceManager(const ResourceManager &);
        ResourceManager & operator= (const ResourceManager &);
    };
}

