
#include "ofxCIBloom.h"

void ofxCIBloom::loadFilter(){
    filter = [CIFilter filterWithName:@"CIBloom"];
    [filter setDefaults]; 
}

void ofxCIBloom::setRadius(int radius){
    radius = ofClamp(radius,0,100);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}

void ofxCIBloom::setIntensity(float intensity){
    intensity = ofClamp(intensity,0,2);
    [filter setValue:[NSNumber numberWithFloat: intensity] forKey:@"inputIntensity"];
}