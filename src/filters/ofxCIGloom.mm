

#include "ofxCIGloom.h"

void ofxCIGloom::loadFilter(){
    filter = [CIFilter filterWithName:@"CIGloom"];
    [filter setDefaults]; 
}

void ofxCIGloom::setRadius(int radius){
    radius = ofClamp(radius,0,100);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}

void ofxCIGloom::setIntensity(float intensity){
    intensity = ofClamp(intensity,0,2);
    [filter setValue:[NSNumber numberWithFloat: intensity] forKey:@"inputIntensity"];
}