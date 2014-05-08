//
//  ofxCoreImage.cpp
//  coreImage_sketch
//
//  Created by Blair Neal on 4/15/14.
//
//

#include "ofxCoreImage.h"


void ofxCI::setup(){
    genericRGB = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
    // Create the pixel format attributes
    NSOpenGLPixelFormatAttribute attr[] = {
        NSOpenGLPFAAccelerated,
        NSOpenGLPFANoRecovery,
        NSOpenGLPFAColorSize, 32,
        0
    };
    CGColorSpaceRelease(genericRGB);
    // Setup the pixel format object:
    pf=[[NSOpenGLPixelFormat alloc] initWithAttributes:attr];
    // Setup the core image context, tied to the OF Open GL context:
    glCIcontext = [CIContext contextWithCGLContext: CGLGetCurrentContext()
                                       pixelFormat: CGLPixelFormatObj(pf)
                                        colorSpace: genericRGB
                                           options: nil];
    
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
    return glCIcontext;
}