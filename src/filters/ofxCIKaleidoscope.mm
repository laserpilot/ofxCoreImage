
#include "ofxCIKaleidoscope.h"

void ofxCIKaleidoscope::loadFilter(){
    filter = [CIFilter filterWithName:@"CIKaleidoscope"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
//-------------------------
void ofxCIKaleidoscope::setAngle(float angle) {
    angle = ofWrap(angle,-PI, PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}
//-------------------------
void ofxCIKaleidoscope::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}
//-------------------------
void ofxCIKaleidoscope::setCount(int count) {
    count = ofClamp(count,0, 50);
    [filter setValue:[NSNumber numberWithFloat: count] forKey:@"inputCount"];
}