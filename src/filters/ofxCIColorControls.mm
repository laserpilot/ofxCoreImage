
#include "ofxCIColorControls.h"

void ofxCIColorControls::loadFilter(){
    filter = [CIFilter filterWithName:@"CIColorControls"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
//SET VALUES
//-------------------------
void ofxCIColorControls::setBrightness(float brightness){
    brightness = ofClamp(brightness,-1, 1);
    
    [filter setValue:[NSNumber numberWithFloat: brightness] forKey:@"inputBrightness"];
}

//-------------------------
void ofxCIColorControls::setContrast(float contrast){
    contrast = ofClamp(contrast,0.25, 4);
    [filter setValue:[NSNumber numberWithFloat: contrast] forKey:@"inputContrast"];
}

//-------------------------
void ofxCIColorControls::setSaturation(float saturation){
    saturation = ofClamp(saturation, 0,2);
    [filter setValue: [NSNumber numberWithFloat: saturation] forKey:@"inputSaturation"];
}