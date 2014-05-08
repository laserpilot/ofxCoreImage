
#include "ofxCIVortexDistortion.h"

void ofxCIVortexDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CIVortexDistortion"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCIVortexDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

void ofxCIVortexDistortion::setRadius(int radius){
    radius = ofClamp(radius,0,800);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
void ofxCIVortexDistortion::setAngle(float angle){
    angle = ofClamp(angle,-30*PI,30*PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}