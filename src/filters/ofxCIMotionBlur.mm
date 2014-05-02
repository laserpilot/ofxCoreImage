
#include "ofxCIMotionBlur.h"

void ofxCIMotionBlur::loadFilter(){
    filter = [CIFilter filterWithName:@"CIMotionBlur"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
void ofxCIMotionBlur::setRadius(int radius){
    radius = ofClamp(radius,0,100);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
//------------------------
void ofxCIMotionBlur::setAngle(float angle){
    angle = ofClamp(angle,-PI/2,PI/2);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}