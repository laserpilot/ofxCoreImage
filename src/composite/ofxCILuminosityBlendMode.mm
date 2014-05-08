
#include "ofxCILuminosityBlendMode.h"

void ofxCILuminosityBlendMode::loadFilter(){
    filter = [CIFilter filterWithName:@"CILuminosityBlendMode"];
    [filter setDefaults]; //always set this on load
}

//Special Compositing Updates

    
void ofxCILuminosityBlendMode::update(ofTexture tex1, ofTexture tex2){ //blend 2 OF textures
    
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
void ofxCILuminosityBlendMode::update(CIImage* inputImage, CIImage* inputBGImage){//don't use both updates with one class...use this for chaining
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputBGImage forKey:@"inputBackgroundImage"];
}
//-------------------------
void ofxCILuminosityBlendMode::update(CIImage* inputImage, ofTexture tex){ //mix an OF texture and a CI filtered image
    
    texID = tex.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputCIImage forKey:@"inputBackgroundImage"];
}