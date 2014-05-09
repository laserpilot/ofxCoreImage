#include "ofxCICopyMachineTransition.h"

void ofxCICopyMachineTransition::loadFilter(){
    filter = [CIFilter filterWithName:@"CICopyMachineTransition"];
    [filter setDefaults]; //always set this on load
}
//-----------------------
void ofxCICopyMachineTransition::update(ofTexture tex1, ofTexture tex2){ //blend 2 OF textures
    
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
void ofxCICopyMachineTransition::setTime(float time){
    time = ofClamp(time,0, 1);
    [filter setValue:[NSNumber numberWithFloat: time] forKey:@"inputTime"];
}
//------------------------
void ofxCICopyMachineTransition::update(CIImage* inputImage, CIImage* inputBGImage){//don't use both updates with one class...use this for chaining
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputBGImage forKey:@"inputTargetImage"];
}
//-------------------------
void ofxCICopyMachineTransition::update(CIImage* inputImage, ofTexture tex){ //mix an OF texture and a CI filtered image
    
    texID = tex.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputCIImage forKey:@"inputTargetImage"];
}

//--------------------------
void ofxCICopyMachineTransition::setAngle(float angle){
    angle = ofWrap(angle,0, 2*PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}
//-------------------------
void ofxCICopyMachineTransition::setWidth(float width){
    width = ofClamp(width,0.1, 500);
    [filter setValue:[NSNumber numberWithFloat: width] forKey:@"inputWidth"];
}
void ofxCICopyMachineTransition::setExtent(int x, int y, int width, int height){
    [filter setValue:[CIVector vectorWithX:x Y:y Z:width W:height] forKey:@"inputExtent"];
}
//--------------------------
void ofxCICopyMachineTransition::setOpacity(float opacity){
    opacity = ofClamp(opacity,0, 3);
    [filter setValue:[NSNumber numberWithFloat: opacity] forKey:@"inputOpacity"];
}
void ofxCICopyMachineTransition::setColor(ofColor color) {
    float red = ofMap(color.r, 0,255,0,1);
    float green = ofMap(color.g, 0,255,0,1);
    float blue = ofMap(color.b, 0,255,0,1);
    float alpha = ofMap(color.a, 0,255,0,1);
    
    [filter  setValue:[CIColor colorWithRed:red green:green blue:blue alpha:alpha] forKey:@"inputColor"];
    
}