//
//  ofxCoreImage.cpp
//  coreImage_sketch
//
//  Created by Blair Neal on 4/15/14.
//
//

#include "ofxCoreImage.h"
CIContext* _glCIcontext = nil;
CGColorSpaceRef _colorSpace = nil;
NSOpenGLPixelFormat *_pf = nil;
NSOpenGLContext* _glContext = nil;

const BOOL OFX_USE_SOFTWARE_RENDERER = NO;

void ofxCI::setup(){
    
    //Took this code from https://github.com/Ahbee/ofxCoreImageFilters in attempt to fix for 0.9.0 and remove glut window dependency, but no joy yet
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        const NSOpenGLPixelFormatAttribute attr[] = {
            NSOpenGLPFAAccelerated,
            NSOpenGLPFANoRecovery,
            NSOpenGLPFAColorSize, 24,
            NSOpenGLPFAAlphaSize,8,
            NSOpenGLPFAOpenGLProfile,NSOpenGLProfileVersionLegacy,
            0
        };
        _colorSpace = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
        _pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:attr];
        _glContext = [[NSOpenGLContext alloc] initWithFormat:_pf shareContext:nil];
        CGLPixelFormatObj pfo = (CGLPixelFormatObj)[_pf CGLPixelFormatObj];
        CGLContextObj gclco = (CGLContextObj)[_glContext CGLContextObj];
        _glCIcontext= [CIContext contextWithCGLContext:gclco pixelFormat:pfo colorSpace:_colorSpace
                                            options:@{kCIContextUseSoftwareRenderer: [NSNumber numberWithBool:OFX_USE_SOFTWARE_RENDERER]}];
        if (_glContext == nil) {
            ofLogError("ofxCI") << "could not create context for Core Image";
            exit(1);
        }
        [_glCIcontext retain];
        NSOpenGLContext* previousContext = [NSOpenGLContext currentContext];
        [_glContext makeCurrentContext];
        glClearColor(0, 0, 0, 1.0);
        [previousContext makeCurrentContext];
    });
    
}

void ofxCI::listAllFilters(){
    
    //[CIPlugIn loadAllPlugIns]; //when you uncomment - lets you access third party plugins
    
    NSArray* filters = [CIFilter filterNamesInCategories:nil];
    
    for (NSString* filterName in filters)
    {
        NSLog(@"Filter: %@", filterName);
        NSLog(@"Parameters: %@", [[CIFilter filterWithName:filterName] attributes]);
    }
}

CIContext* ofxCI::getCIContext(){
    return _glCIcontext;
}