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

class ofxCIRippleTransition{
    
//This filters takes 3 textures to work - you need a shading texture and a target/source texture. You can also just send one of those to the shading target if you want. I think it just adds normals and specularity to the "water" ripples
    
public:
 
    
    void setup(int width, int height, CIContext* _glCIcontext){
        genericRGB = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
        
        glCIcontext = _glCIcontext;
        
        texSize = CGSizeMake(width, height);
        inRect = CGRectMake(0,0,width,height);
        outRect = CGRectMake(0,0,width,height); //these set the final drawing sizes
        
        filter = [CIFilter filterWithName:@"CIRippleTransition"];
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
        [filter setValue:inputBGCIImage forKey:@"inputTargetImage"];
    }

    
    void updateShadingTexture(ofTexture tex){
        texID = tex.texData.textureID;
        
        inputShadingImage = [CIImage imageWithTexture:texID
                                            size:texSize
                                         flipped:NO
                                      colorSpace:genericRGB];
        
                [filter setValue:inputShadingImage forKey:@"inputShadingImage"];
    }

    //-------------------------
    void setScale(float scale){
        //make this higher for proper effect. Positive or negative makes the ripple start up or down
        scale = ofClamp(scale,-50, 50);
        [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"]; 
    }
    //-------------------------
    void setExtent(int x, int y, int width, int height){
        [filter setValue:[CIVector vectorWithX:x Y:y Z:width W:height] forKey:@"inputExtent"];
    }
    //-------------------------
    void setTime(float time){
        time = ofClamp(time,0, 1);
        [filter setValue:[NSNumber numberWithFloat: time] forKey:@"inputTime"];
    }
    //-------------------------
    void setCenter(int x, int y) {
        [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
    }
    //-------------------------
    void setWidth(float width){
        width = ofClamp(width,0, 1500);
        [filter setValue:[NSNumber numberWithFloat: width] forKey:@"inputWidth"];
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
    
    void draw(int x, int y, int width, int height){
        
        inRect = CGRectMake(0,0,width,height);
        outRect = CGRectMake(0,0,width,height); //these set the final drawing sizes
        
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
    CIImage*    inputShadingImage;
    CIFilter* filter;
};