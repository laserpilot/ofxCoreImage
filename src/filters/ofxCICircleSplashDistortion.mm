
#include "ofxCICircleSplashDistortion.h"

void ofxCICircleSplashDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CICircleSplashDistortion"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
//SET VALUES
void ofxCICircleSplashDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

void ofxCICircleSplashDistortion::setRadius(int radius){
    radius = ofClamp(radius,0,1000);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}