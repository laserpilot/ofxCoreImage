//
//  ofxEasyCI.h
//  coreImage_sketch
//
//  Created by Blair Neal on 4/15/14.
//
//

#pragma once
#include "ofMain.h"
#include "ofxCoreImage.h"

class ofxCILineScreen{
    
    //This CI Filter lets you adjust brightness, saturation and contrast
    
public:
 
    
    void setup(int width, int height, CIContext* _glCIcontext){
        
        genericRGB = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
        
        glCIcontext = _glCIcontext;
        
        texSize = CGSizeMake(width, height);
        inRect = CGRectMake(0,0,width,height);
        outRect = CGRectMake(0,0,width,height);
        
        filter = [CIFilter filterWithName:@"CILineScreen"];
        [filter setDefaults]; //always do this on load
    }

    //-------------------------
    void update(ofTexture tex){ //this takes an ofTexture and
        
        texID = tex.texData.textureID;
        
        inputCIImage = [CIImage imageWithTexture:texID
                                            size:texSize
                                         flipped:NO
                                      colorSpace:genericRGB];
        
        [filter setValue:inputCIImage forKey:@"inputImage"];
    }
    
    //-------------------------
    void update(CIImage* inputImage){//don't use both updates with one class...use this for chaining - you need to start with an OF texture first though
        [filter setValue:inputImage forKey:@"inputImage"];
        
    }
    
    //-------------------------
    void setSharpness(float sharpness){
        sharpness = ofClamp(sharpness,0, 1);
        [filter setValue:[NSNumber numberWithFloat: sharpness] forKey:@"inputSharpness"];
    }
    //-------------------------
    void setWidth(float scale){
        scale = ofClamp(scale,0, 50);
        [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputWidth"];
    }
    //-------------------------
    void setCenter(int x, int y) {
        [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
    }
    void setAngle(float angle){
        angle = ofWrap(angle,-PI/2,PI/2);
        [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
    }
    //-------------------------
    void setDefaults(){
        [filter setDefaults];
    }
    
    //-------------------------
    CIImage* getCIImage(){ //use this to pass into other effects for chaining
        filterCIImage = [filter valueForKey:@"outputImage"];
        return filterCIImage;
    }
    
    //-------------------------
    void draw(int x, int y){
        
        filterCIImage = [filter valueForKey:@"outputImage"];
        ofPushMatrix();
        ofTranslate(x,y);

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