
#include "ofxCIToneCurve.h"

void ofxCIToneCurve::loadFilter(){
    filter = [CIFilter filterWithName:@"CIToneCurve"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCIToneCurve::setPoint0(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputPoint0"];
}

void ofxCIToneCurve::setPoint1(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputPoint1"];
}

void ofxCIToneCurve::setPoint2(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputPoint2"];
}

void ofxCIToneCurve::setPoint3(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputPoint3"];
}