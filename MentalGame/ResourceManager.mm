//
//  ResourceManager.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 10.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "ResourceManager.h"



namespace Renderer {
    
    ResourceManager::ResourceManager() {
        
    }
    
    string ResourceManager::LoadTextFileNamed(const string &fileName) const {
        NSString *nameOfFile = [NSString stringWithCString:fileName.c_str() encoding:NSUTF8StringEncoding];
        
        NSString *resourcePath = [NSBundle mainBundle].resourcePath;
        NSString *filePath = [resourcePath stringByAppendingPathComponent:nameOfFile];
        
        NSString *fileContents = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:nil];
        
        string contents = string([fileContents cStringUsingEncoding:NSUTF8StringEncoding]);
        
        return contents;
    }
    
    TextureImage * ResourceManager::LoadTexturePOT(const string &fileName) const {
        // Load image
        NSString *resourceName = [NSString stringWithCString:fileName.c_str() encoding:NSUTF8StringEncoding];
        NSString *resourcePath = [[NSBundle mainBundle] pathForResource:resourceName ofType:nil];
        UIImage *image = [UIImage imageWithContentsOfFile:resourcePath];
        
        // Get image info
        CGDataProviderRef dataProviderRef = CGImageGetDataProvider(image.CGImage);
        NSData *data = CFBridgingRelease(CGDataProviderCopyData(dataProviderRef));
        void *bytes = malloc(data.length);
        [data getBytes:bytes length:data.length];
        
        CSize textureSize(CGImageGetWidth(image.CGImage), CGImageGetHeight(image.CGImage));
        BITS_PER_COMPONENT bitsPerComponent = (BITS_PER_COMPONENT)CGImageGetBitsPerComponent(image.CGImage);
        
        BOOL hasAlpha = (CGImageGetAlphaInfo(image.CGImage) != kCGImageAlphaNone);
        
        CGColorSpaceRef colorSpaceRef = CGImageGetColorSpace(image.CGImage);
        CGColorSpaceModel colorSpaceModel = CGColorSpaceGetModel(colorSpaceRef);
        
        // TODO: Format Alpha not handled
        PIXEL_FORMAT pixelFormat = PIXEL_FORMAT_NONE;
        switch (colorSpaceModel) {
            case kCGColorSpaceModelMonochrome: {
                pixelFormat = hasAlpha ? PIXEL_FORMAT_LUMINANCE_ALPHA : PIXEL_FORMAT_LUMINANCE;
                break;
            }
            case kCGColorSpaceModelRGB: {
                pixelFormat = hasAlpha ? PIXEL_FORMAT_RGBA : PIXEL_FORMAT_RGB;
                break;
            }
            default: {
                assert(!"Unsupported color space");
                break;
            }
        }
        
        // Pixel type
        PIXEL_TYPE pixelType = PIXEL_TYPE_NONE;
        
        switch (bitsPerComponent) {
            case BITS_PER_COMPONENT_4: {
                if (pixelFormat == PIXEL_FORMAT_RGBA) {
                    pixelType = PIXEL_TYPE_USHORT_4_4_4_4;
                    break;
                }
            }
            case BITS_PER_COMPONENT_8: {
                pixelType = PIXEL_TYPE_UBYTE;
                break;
            }
            default: {
                assert(!"Unsupported format");
            }
        }
        
        TextureImage *pTextureImage = new TextureImage(textureSize, pixelFormat, pixelType, bytes);
        return pTextureImage;
    }
}
