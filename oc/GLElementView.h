//
//  GLElementView.h
//  glui
//
//  Created by zhang hailong on 14-6-24.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GLElementView : UIView

@property(assign) void * element;
@property(nonatomic,readonly) CGSize viewport;

-(void) glDrawContext:(void *) context;

@end
