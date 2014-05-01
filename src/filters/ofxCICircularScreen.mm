
#include "ofxCICircularScreen.h"

void ofxCICircularScreen::loadFilter(){
    filter = [CIFilter filterWithName:@"CICircularScreen"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCICircularScreen::setSharpness(float sharpness){
    sharpness = ofClamp(sharpness,0, 1);
    [filter setValue:[NSNumber numberWithFloat: sharpness] forKey:@"inputSharpness"];
}
//-------------------------
void ofxCICircularScreen::setWidth(float scale){
    scale = ofClamp(scale,0, 50);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputWidth"];
}
//-------------------------
void ofxCICircularScreen::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}