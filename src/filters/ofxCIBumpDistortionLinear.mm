
#include "ofxCIBumpDistortionLinear.h"

void ofxCIBumpDistortionLinear::loadFilter(){
    filter = [CIFilter filterWithName:@"CIBumpDistortionLinear"];
    [filter setDefaults]; //always set this on load

}

//-------------------------
//SET VALUES
void ofxCIBumpDistortionLinear::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}
void ofxCIBumpDistortionLinear::setRadius(int radius){
    radius = ofClamp(radius,0,600);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
void ofxCIBumpDistortionLinear::setScale(float scale){
    scale = ofClamp(scale,0,2);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}
void ofxCIBumpDistortionLinear::setAngle(float angle){
    angle = ofWrap(angle,0,PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}
