#include "ofxCIBarsSwipeTransition.h"

void ofxCIBarsSwipeTransition::loadFilter(){
    filter = [CIFilter filterWithName:@"CIBarsSwipeTransition"];
    [filter setDefaults]; //always set this on load
}
//-----------------------
void ofxCIBarsSwipeTransition::update(ofTexture tex1, ofTexture tex2){ //blend 2 OF textures
    
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
void ofxCIBarsSwipeTransition::setTime(float time){
    time = ofClamp(time,0, 1);
    [filter setValue:[NSNumber numberWithFloat: time] forKey:@"inputTime"];
}
//------------------------
void ofxCIBarsSwipeTransition::update(CIImage* inputImage, CIImage* inputBGImage){//don't use both updates with one class...use this for chaining
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputBGImage forKey:@"inputTargetImage"];
}
//-------------------------
void ofxCIBarsSwipeTransition::update(CIImage* inputImage, ofTexture tex){ //mix an OF texture and a CI filtered image
    
    texID = tex.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputCIImage forKey:@"inputTargetImage"];
}

//--------------------------
void ofxCIBarsSwipeTransition::setAngle(float angle){
    angle = ofWrap(angle,0, 2*PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}
//-------------------------
void ofxCIBarsSwipeTransition::setWidth(int width){
    width = ofClamp(width,2, 300);
    [filter setValue:[NSNumber numberWithFloat: width] forKey:@"inputWidth"];
}
//-------------------------
void ofxCIBarsSwipeTransition::setBarOffset(int offset){
    offset = ofClamp(offset,1, 100);
    [filter setValue:[NSNumber numberWithFloat: offset] forKey:@"inputBarOffset"];
}
