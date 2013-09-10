//
//  ResourceManager.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "ResourceManager.h"
#include <iostream>
#include <string>

using namespace std;



string ResourceManager::LoadTextFileNamed(const string &fileName) const
{
    NSString *nameOfFile = [NSString stringWithCString:fileName.c_str() encoding:NSUTF8StringEncoding];
    
    NSString *resourcePath = [NSBundle mainBundle].resourcePath;
    NSString *filePath = [resourcePath stringByAppendingPathComponent:nameOfFile];
    
    NSString *fileContents = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:nil];
    
    string contents = string([fileContents cStringUsingEncoding:NSUTF8StringEncoding]);
    
    return contents;
}