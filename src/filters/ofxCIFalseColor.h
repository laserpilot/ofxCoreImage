//
//  ofxEasyCI.h
//  coreImage_sketch
//
//  Created by Blair Neal on 4/15/14.
//
//

#pragma once
#include "ofMain.h"
#import <QuartzCore/QuartzCore.h> 
#include "ofxCoreImage.h"

class ofxCIFalseColor{
    
public:
 
    
    void setup(int width, int height, CIContext* _glCIcontext){
        genericRGB = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
        
        glCIcontext = _glCIcontext;
        
        texSize = CGSizeMake(width, height);
        inRect = CGRectMake(0,0,width,height);
        outRect = CGRectMake(0,0,width,height);
        
        filter = [CIFilter filterWithName:@"CIFalseColor"];
        [filter setDefaults]; //always set this on load
    }

    
    void update(ofTexture tex){ //this takes an ofTexture and lets you
        
        texID = tex.texData.textureID;
        
        inputCIImage = [CIImage imageWithTexture:texID
                                            size:texSize
                                         flipped:NO
                                      colorSpace:genericRGB];
        
        [filter setValue:inputCIImage forKey:@"inputImage"];
    }
    
    void update(CIImage* inputImage){//don't use both updates with one class...use this for chaining
        [filter setValue:inputImage forKey:@"inputImage"];
        
    }
    //-------------------------
    void setColor1(ofColor color1) {
        float red = ofMap(color1.r, 0,255,0,1);
        float green = ofMap(color1.g, 0,255,0,1);
        float blue = ofMap(color1.b, 0,255,0,1);
        float alpha = ofMap(color1.a, 0,255,0,1);

        [filter  setValue:[CIColor colorWithRed:red green:green blue:blue alpha:alpha] forKey:@"inputColor0"];

    }
    //-------------------------
    void setColor2(ofColor color2) {
        float red = ofMap(color2.r, 0,255,0,1);
        float green = ofMap(color2.g, 0,255,0,1);
        float blue = ofMap(color2.b, 0,255,0,1);
        float alpha = ofMap(color2.a, 0,255,0,1);
        
        [filter  setValue:[CIColor colorWithRed:red green:green blue:blue alpha:alpha] forKey:@"inputColor1"];
        
    }
    //-------------------------
    void setDefaults(){
        [filter setDefaults];
    }
    
    CIImage* getCIImage(){ //use this to pass into other effects for chaining
        filterCIImage = [filter valueForKey:@"outputImage"];
        return filterCIImage;
    }

    
    void draw(int x, int y){
        
        filterCIImage = [filter valueForKey:@"outputImage"];
        ofPushMatrix();
        ofTranslate(x,y);
        ofSetColor(255);
        [glCIcontext drawImage:filterCIImage
                        inRect:outRect
                      fromRect:inRect];
        ofPopMatrix();
    }
    
    
private:
    
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
};