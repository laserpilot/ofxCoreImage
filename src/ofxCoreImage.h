/*
 *  ofxCoreImage
 *
 *  Created by Blair Neal on 04/26/14.
 *  Copyright 2014 http://www.blairneal.com All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the author nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 *  OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *  OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  ************************************************************************************
 */


#pragma once


#include "ofMain.h"

#ifdef __OBJC__
#import <QuartzCore/QuartzCore.h>
#elif defined(__cplusplus)
class CIContext;
class CIImage;
class CIFilter;
class NSOpenGLPixelFormatAttribute;
class NSOpenGLPixelFormat;
#endif

#include "ofxCIFilter.h"

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
#include "filters/ofxCIBumpDistortionLinear.h"
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
#include "filters/ofxCIZoomBlur.h"
#include "filters/ofxCIFalseColor.h"
#include "filters/ofxCIColorMonochrome.h"


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

//Transitions
#include "transitions/ofxCIRippleTransition.h"
#include "transitions/ofxCIDissolveTransition.h"

//This implementation of Core Image is for really easy application of standard filters to OF sketches

class ofxCI{
    
public:
    
    
    void setup(); //use this to set up your shared CI context
    void listAllFilters();
    
	CIContext * getCIContext();
	
    CIContext*  glCIcontext;
    CIImage*    inputCIImage;
    CIFilter* filter;
	NSOpenGLPixelFormatAttribute*   attr;
    NSOpenGLPixelFormat*    pf;
	CIImage*    filterCIImage;
	
    CGLContextObj   CGLContext;
    CGColorSpaceRef genericRGB;
    CGSize      texSize;
    GLint       texID;
    CGRect      outRect;
    CGRect      inRect;
};