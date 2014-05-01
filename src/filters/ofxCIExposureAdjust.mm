
#include "ofxCIExposureAdjust.h"

void ofxCIExposureAdjust::loadFilter(){
    filter = [CIFilter filterWithName:@"CIExposureAdjust"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
void ofxCIExposureAdjust::setIntensity(float intensity){
    intensity = ofClamp(intensity,-10, 10);
    [filter setValue:[NSNumber numberWithFloat: intensity] forKey:@"inputEV"];
}