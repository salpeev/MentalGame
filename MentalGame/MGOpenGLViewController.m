//
//  MGOpenGLViewController.m
//  MentalGame
//
//  Created by Sergey Alpeev on 07.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#import "MGOpenGLViewController.h"
#import "MGOpenGLView.h"



@interface MGOpenGLViewController ()

@end



@implementation MGOpenGLViewController

#pragma mark - Lifecycle

- (id)init
{
    self = [super init];
    if (self) {
        
    }
    return self;
}

#pragma mark - View Lifecycle

- (void)loadView
{
    CGRect screenBounds = [UIScreen mainScreen].bounds;
    
    MGOpenGLView *openglView = [[MGOpenGLView alloc] initWithFrame:screenBounds];
    self.view = openglView;
}

@end
