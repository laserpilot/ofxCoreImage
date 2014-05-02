
#include "ofxCIPointillize.h"

void ofxCIPointillize::loadFilter(){
    filter = [CIFilter filterWithName:@"CIPointillize"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCIPointillize::setRadius(float radius){
    radius = ofClamp(radius,1, 100);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
//-------------------------
void ofxCIPointillize::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}