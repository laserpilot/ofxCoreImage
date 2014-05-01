
#include "ofxCIGammaAdjust.h"

void ofxCIGammaAdjust::loadFilter(){
    filter = [CIFilter filterWithName:@"CIGammaAdjust"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
void ofxCIGammaAdjust::setPower(float power){
    power = ofClamp(power,0.1, 3);
    [filter setValue:[NSNumber numberWithFloat: power] forKey:@"inputPower"];
}