//
//  ResourceManager.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include <string>

using namespace std;



class ResourceManager
{
public:
    static const ResourceManager & SharedInstance()
    {
        static ResourceManager resourceManager;
        return resourceManager;
    }
    
    string LoadTextFileNamed(const string &fileName) const;
    
private:
    ResourceManager(){}
    ResourceManager(const ResourceManager &resourceManager);
    ResourceManager & operator= (const ResourceManager &);
};
