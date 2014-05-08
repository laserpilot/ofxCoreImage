#include "ofxCIDissolveTransition.h"

void ofxCIDissolveTransition::loadFilter(){
    filter = [CIFilter filterWithName:@"CIDissolveTransition"];
    [filter setDefaults]; //always set this on load
}
//-----------------------
void ofxCIDissolveTransition::update(ofTexture tex1, ofTexture tex2){ //blend 2 OF textures
    
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
//-------------------------
void ofxCIDissolveTransition::setTime(float time){
    time = ofClamp(time,0, 1);
    [filter setValue:[NSNumber numberWithFloat: time] forKey:@"inputTime"];
}
//------------------------
void ofxCIDissolveTransition::update(CIImage* inputImage, CIImage* inputBGImage){//don't use both updates with one class...use this for chaining
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputBGImage forKey:@"inputBackgroundImage"];
}
//-------------------------
void ofxCIDissolveTransition::update(CIImage* inputImage, ofTexture tex){ //mix an OF texture and a CI filtered image
    
    texID = tex.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputCIImage forKey:@"inputBackgroundImage"];
}