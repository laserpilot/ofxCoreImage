/*
 *  ofxCIFilter
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
#ifndef OFXCIFILTER
#define OFXCIFILTER

#pragma once

#include "ofMain.h"
#include <OpenGL/OpenGL.h>

#if defined(__OBJC__)
#import <QuartzCore/QuartzCore.h>
#elif defined(__cplusplus)
class CIImage;
class CIContext;
class CIFilter;

#endif

class ofxCIFilter
{
    
    
public:
    ofxCIFilter(){};
    void setup(int width, int height, CIContext* _glCIcontext);
    virtual void loadFilter(); //this method is overloaded with "virtual" - each subclass will load its own filter using this method
    void update(ofTexture tex);
    void update(CIImage* inputImage);//don't use both updates in one instance...use this for chaining
    void setDefaults();
    
    void draw(int x, int y);
    void draw(int x, int y, int width, int height);
    
	CIImage * getCIImage();
    
	CIFilter* filter;
    
protected:
    
    CGLContextObj   CGLContext;
    CGColorSpaceRef genericRGB;
    CGSize      texSize;
    GLint       texID;
    CGRect      outRect;
    CGRect      inRect;
	
	NSOpenGLPixelFormatAttribute*   attr;
    NSOpenGLPixelFormat*    pf;
	CIImage*    filterCIImage;
    CIContext*  glCIcontext;
    CIImage*    inputCIImage;
};

#endif