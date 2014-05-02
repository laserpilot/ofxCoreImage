
#include "ofxCIFalseColor.h"

void ofxCIFalseColor::loadFilter(){
    filter = [CIFilter filterWithName:@"CIFalseColor"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
void ofxCIFalseColor::setColor1(ofColor color1) {
    float red = ofMap(color1.r, 0,255,0,1);
    float green = ofMap(color1.g, 0,255,0,1);
    float blue = ofMap(color1.b, 0,255,0,1);
    float alpha = ofMap(color1.a, 0,255,0,1);
    
    [filter  setValue:[CIColor colorWithRed:red green:green blue:blue alpha:alpha] forKey:@"inputColor0"];
    
}
//-------------------------
void ofxCIFalseColor::setColor2(ofColor color2) {
    float red = ofMap(color2.r, 0,255,0,1);
    float green = ofMap(color2.g, 0,255,0,1);
    float blue = ofMap(color2.b, 0,255,0,1);
    float alpha = ofMap(color2.a, 0,255,0,1);
    
    [filter  setValue:[CIColor colorWithRed:red green:green blue:blue alpha:alpha] forKey:@"inputColor1"];
    
}