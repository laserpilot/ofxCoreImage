#include "ofxCIRippleTransition.h"

void ofxCIRippleTransition::loadFilter(){
    filter = [CIFilter filterWithName:@"CIRippleTransition"];
    [filter setDefaults]; //always set this on load
}
//-----------------------
void ofxCIRippleTransition::update(ofTexture tex1, ofTexture tex2){ //blend 2 OF textures
    
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


void ofxCIRippleTransition::updateShadingTexture(ofTexture tex){
    texID = tex.texData.textureID;
    
    inputShadingImage = [CIImage imageWithTexture:texID
                                             size:texSize
                                          flipped:NO
                                       colorSpace:genericRGB];
    
    [filter setValue:inputShadingImage forKey:@"inputShadingImage"];
}

//-------------------------
void ofxCIRippleTransition::setScale(float scale){
    //make this higher for proper effect. Positive or negative makes the ripple start up or down
    scale = ofClamp(scale,-50, 50);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}
//-------------------------
void ofxCIRippleTransition::setExtent(int x, int y, int width, int height){
    [filter setValue:[CIVector vectorWithX:x Y:y Z:width W:height] forKey:@"inputExtent"];
}
//-------------------------
void ofxCIRippleTransition::setTime(float time){
    time = ofClamp(time,0, 1);
    [filter setValue:[NSNumber numberWithFloat: time] forKey:@"inputTime"];
}
//-------------------------
void ofxCIRippleTransition::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}
//-------------------------
void ofxCIRippleTransition::setWidth(float width){
    width = ofClamp(width,0, 1500);
    [filter setValue:[NSNumber numberWithFloat: width] forKey:@"inputWidth"];
}
//------------------------
void ofxCIRippleTransition::update(CIImage* inputImage, CIImage* inputBGImage){//don't use both updates with one class...use this for chaining
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputBGImage forKey:@"inputBackgroundImage"];
}
//-------------------------
void ofxCIRippleTransition::update(CIImage* inputImage, ofTexture tex){ //mix an OF texture and a CI filtered image
    
    texID = tex.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputCIImage forKey:@"inputBackgroundImage"];
}