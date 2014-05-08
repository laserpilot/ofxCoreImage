#include "ofxCIHoleDistortion.h"

void ofxCIHoleDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CIHoleDistortion"];
    [filter setDefaults]; 
}
//-------------------------
//SET VALUES
void ofxCIHoleDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

void ofxCIHoleDistortion::setRadius(int radius){
    radius = ofClamp(radius,0,1500);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}