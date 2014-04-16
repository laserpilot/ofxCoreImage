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

class ofxCIDroste{
    
    //This applies a gaussian blur core iamge filter
    
public:
 
    
    void setup(int width, int height, CIContext* _glCIcontext){
        genericRGB = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
        
        glCIcontext = _glCIcontext;
        
        texSize = CGSizeMake(width, height);
        inRect = CGRectMake(0,0,width,height);
        outRect = CGRectMake(0,0,width,height);
        
        filter = [CIFilter filterWithName:@"CIDroste"];
        [filter setDefaults]; //always set this on load
    }

    
    void update(ofTexture tex){ //this takes an ofTexture and turns it into a CI image for the filters
        
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
    //SET VALUES
    void setPoint0(int x, int y) {
        [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputInsetPoint0"];
    }
    
    void setPoint1(int x, int y) {
        [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputInsetPoint1"];
    }
    
    void setPeriodicity(int periodicity){
        periodicity = ofClamp(periodicity,0,1500);
        [filter setValue:[NSNumber numberWithFloat: periodicity] forKey:@"inputPeriodicity"];
    }
    
    void setRotation(float rotation){
        rotation = ofWrap(rotation,0,2*PI);
        [filter setValue:[NSNumber numberWithFloat: rotation] forKey:@"inputRotation"];
    }
    
    void setStrands(float strands){
        strands = ofClamp(strands,0,10);
        [filter setValue:[NSNumber numberWithFloat: strands] forKey:@"inputStrands"];
    }
    void setZoom(float zoom){
        zoom = ofClamp(zoom,0.1,5);
        [filter setValue:[NSNumber numberWithFloat: zoom] forKey:@"inputZoom"];
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