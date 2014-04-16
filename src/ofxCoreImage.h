
//
//  ofxCoreImage.h
//  coreImage_sketch
//
//  Created by Blair Neal on 4/15/14.
//
//
#pragma once
#include "ofMain.h"
#import <QuartzCore/QuartzCore.h> 

//general image filters
#include "filters/ofxCIBlur.h"
#include "filters/ofxCIHue.h"
#include "filters/ofxCIColorControls.h"
#include "filters/ofxCICrystallize.h"
#include "filters/ofxCIKaleidoscope.h"
#include "filters/ofxCIBloom.h"
#include "filters/ofxCIPinchDistortion.h"
#include "filters/ofxCITwirlDistortion.h"
#include "filters/ofxCIBumpDistortion.h"
#include "filters/ofxCIHexagonalPixellate.h"
#include "filters/ofxCIPixellate.h"
#include "filters/ofxCIVortexDistortion.h"
#include "filters/ofxCIHoleDistortion.h"
#include "filters/ofxCICircleSplashDistortion.h"
#include "filters/ofxCICircularWrapDistortion.h"
#include "filters/ofxCIGlassDistortion.h"
#include "filters/ofxCIGlassLozenge.h"
#include "filters/ofxCIBumpDistortion.h"
#include "filters/ofxCIColorPosterize.h"
#include "filters/ofxCIDroste.h"
#include "filters/ofxCIEdges.h"
#include "filters/ofxCIExposureAdjust.h"
#include "filters/ofxCIGammaAdjust.h"
#include "filters/ofxCIGloom.h"
#include "filters/ofxCIEdgeWork.h"
#include "filters/ofxCIColorInvert.h"
#include "filters/ofxCIBoxBlur.h"
#include "filters/ofxCICircularScreen.h"
#include "filters/ofxCILineScreen.h"
#include "filters/ofxCITorusLensDistortion.h"
#include "filters/ofxCIPointillize.h"
#include "filters/ofxCIOpTile.h"
#include "filters/ofxCIMotionBlur.h"
#include "filters/ofxCIToneCurve.h"


//composite filters
#include "composite/ofxCIAdditionCompositing.h"
#include "composite/ofxCIColorBlendMode.h"
#include "composite/ofxCIColorBurnBlendMode.h"
#include "composite/ofxCIColorDodgeBlendMode.h"
#include "composite/ofxCIDarkenBlendMode.h"
#include "composite/ofxCIDifferenceBlendMode.h"
#include "composite/ofxCIExclusionBlendMode.h"
#include "composite/ofxCIHardLightBlendMode.h"
#include "composite/ofxCIHueBlendMode.h"
#include "composite/ofxCILightenBlendMode.h"
#include "composite/ofxCILuminosityBlendMode.h"
#include "composite/ofxCIMultiplyBlendMode.h"
#include "composite/ofxCIOverlayBlendMode.h"
#include "composite/ofxCISaturationBlendMode.h"
#include "composite/ofxCIScreenBlendMode.h"
#include "composite/ofxCISoftLightBlendMode.h"
#include "composite/ofxCISourceAtopCompositing.h"
#include "composite/ofxCISourceInCompositing.h"
#include "composite/ofxCISourceOutCompositing.h"
#include "composite/ofxCISourceOverCompositing.h"


//This implementation of Core Image is for really easy application of standard filters to OF sketches

//DO NOT USE THIS IN PRODUCTION - yet - memory leaks are probably everywhere

class ofxCI{
    
    //This applies a gaussian blur core iamge filter
    
public:
    
    CGLContextObj   CGLContext;
    NSOpenGLPixelFormatAttribute*   attr;
    NSOpenGLPixelFormat*    pf;
    CGColorSpaceRef genericRGB;
    CIImage*    filterCIImage;
    CGSize      texSize;
    GLint       texID;
    CGRect      outRect;
    CGRect      inRect;
    CIContext*  glCIcontext;
    CIImage*    inputCIImage;
    CIFilter* filter;
    
    void setup(){
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
    
    void listAllFilters(){
        
           //[CIPlugIn loadAllPlugIns]; //when you uncomment - lets you access third party plugins
        
            NSArray* filters = [CIFilter filterNamesInCategories:nil];
        
            for (NSString* filterName in filters)
            {
                NSLog(@"Filter: %@", filterName);
                NSLog(@"Parameters: %@", [[CIFilter filterWithName:filterName] attributes]);
            }
    }
    


};