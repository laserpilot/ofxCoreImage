
#include "ofxCIPinchDistortion.h"

void ofxCIPinchDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CIPinchDistortion"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
void ofxCIPinchDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

void ofxCIPinchDistortion::setRadius(int radius){
    radius = ofClamp(radius,0,1000);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
void ofxCIPinchDistortion::setScale(float scale){
    scale = ofClamp(scale,0,3);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}