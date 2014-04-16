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

class ofxCISourceOverCompositing{
    

    
public:
 
    
    void setup(int width, int height, CIContext* _glCIcontext){
        genericRGB = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
        
        glCIcontext = _glCIcontext;
        
        texSize = CGSizeMake(width, height);
        inRect = CGRectMake(0,0,width,height);
        outRect = CGRectMake(0,0,width,height);
        
        filter = [CIFilter filterWithName:@"CISourceOverCompositing"];
        [filter setDefaults]; //always set this on load
    }

    //-----------------------
    void update(ofTexture tex1, ofTexture tex2){ //blend 2 OF textures
        
        texID = tex1.texData.textureID;
        
        inputCIImage = [CIImage imageWithTexture:texID
                                            size:texSize
                                         flipped:NO
                                      colorSpace:genericRGB];
        
        texID2 = tex2.texData.textureID;
        
        inputBGCIImage = [CIImage imageWithTexture:texID2
                                            size:texSize
                                         flipped:NO
                                      colorSpace:genericRGB];
        
        [filter setValue:inputCIImage forKey:@"inputImage"];
        [filter setValue:inputBGCIImage forKey:@"inputBackgroundImage"];
    }
    //------------------------
    void update(CIImage* inputImage, CIImage* inputBGImage){//don't use both updates with one class...use this for chaining
        [filter setValue:inputImage forKey:@"inputImage"];
        [filter setValue:inputBGImage forKey:@"inputBackgroundImage"];
    }
    //-------------------------
    void update(CIImage* inputImage, ofTexture tex){ //mix an OF texture and a CI filtered image
        
        texID = tex.texData.textureID;
        
        inputCIImage = [CIImage imageWithTexture:texID
                                            size:texSize
                                         flipped:NO
                                      colorSpace:genericRGB];
        
        
        [filter setValue:inputImage forKey:@"inputImage"];
        [filter setValue:inputCIImage forKey:@"inputBackgroundImage"];
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
    GLint       texID, texID2;
    CGRect      outRect;
    CGRect      inRect;
    CIContext*  glCIcontext;
    CIImage*    inputCIImage;
    CIImage*    inputBGCIImage;
    CIFilter* filter;
};