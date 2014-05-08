
#include "ofxCILineScreen.h"

void ofxCILineScreen::loadFilter(){
    filter = [CIFilter filterWithName:@"CILineScreen"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCILineScreen::setSharpness(float sharpness){
    sharpness = ofClamp(sharpness,0, 1);
    [filter setValue:[NSNumber numberWithFloat: sharpness] forKey:@"inputSharpness"];
}
//-------------------------
void ofxCILineScreen::setWidth(float scale){
    scale = ofClamp(scale,0, 50);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputWidth"];
}
//-------------------------
void ofxCILineScreen::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}
void ofxCILineScreen::setAngle(float angle){
    angle = ofWrap(angle,-PI/2,PI/2);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}
