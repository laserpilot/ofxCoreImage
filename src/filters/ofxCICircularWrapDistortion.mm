
#include "ofxCICircularWrapDistortion.h"

void ofxCICircularWrap::loadFilter(){
    filter = [CIFilter filterWithName:@"CICircularWrap"];
    [filter setDefaults]; //always set this on load

}

//-------------------------
//SET VALUES
void ofxCICircularWrap::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}
void ofxCICircularWrap::setRadius(int radius){
    radius = ofClamp(radius,0,600);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
void ofxCICircularWrap::setAngle(float angle){
    angle = ofWrap(angle,-PI/2,PI/2);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}
