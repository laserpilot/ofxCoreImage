
#include "ofxCITwirlDistortion.h"

void ofxCITwirlDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CITwirlDistortion"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCITwirlDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

void ofxCITwirlDistortion::setRadius(int radius){
    radius = ofClamp(radius,0,500);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
void ofxCITwirlDistortion::setAngle(float angle){
    angle = ofWrap(angle,-4*PI,4*PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}