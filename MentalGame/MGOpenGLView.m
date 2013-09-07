//
//  MGOpenGLView.m
//  MentalGame
//
//  Created by Sergey Alpeev on 07.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#import "MGOpenGLView.h"
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h>



@interface MGOpenGLView ()

@property (strong, nonatomic) EAGLContext *eaglContext;

- (void)draw:(CADisplayLink *)displayLink;

@end



@implementation MGOpenGLView

#pragma mark - Lifecycle

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        CADisplayLink *displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(draw:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    }
    return self;
}

#pragma mark - Private Methods

- (void)draw:(CADisplayLink *)displayLink
{
    NSLog(@"%@", displayLink);
}

@end
