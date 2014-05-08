
#include "ofxCIColorMonochrome.h"

void ofxCIColorMonochrome::loadFilter(){
    filter = [CIFilter filterWithName:@"CIColorMonochrome"];
    [filter setDefaults]; //always set this on load
}
//-------------------------
void ofxCIColorMonochrome::setColor(ofColor color1) {
    
    float red = ofMap(color1.r, 0,255,0,1);
    float green = ofMap(color1.g, 0,255,0,1);
    float blue = ofMap(color1.b, 0,255,0,1);
    float alpha = ofMap(color1.a, 0,255,0,1);
    
    [filter  setValue:[CIColor colorWithRed:red green:green blue:blue alpha:alpha] forKey:@"inputColor"];
    
}
//------------------------
void ofxCIColorMonochrome::setIntensity(float intensity){
    
    intensity = ofClamp(intensity,0,1);
    [filter setValue:[NSNumber numberWithFloat: intensity] forKey:@"inputIntensity"];
}