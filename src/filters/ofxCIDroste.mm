
#include "ofxCIDroste.h"

void ofxCIDroste::loadFilter(){
    filter = [CIFilter filterWithName:@"CIDroste"];
    [filter setDefaults]; //always set this on load
}
//------------
void ofxCIDroste::setPoint0(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputInsetPoint0"];
}

void ofxCIDroste::setPoint1(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputInsetPoint1"];
}

void ofxCIDroste::setPeriodicity(int periodicity){
    periodicity = ofClamp(periodicity,0,1500);
    [filter setValue:[NSNumber numberWithFloat: periodicity] forKey:@"inputPeriodicity"];
}

void ofxCIDroste::setRotation(float rotation){
    rotation = ofWrap(rotation,0,2*PI);
    [filter setValue:[NSNumber numberWithFloat: rotation] forKey:@"inputRotation"];
}

void ofxCIDroste::setStrands(float strands){
    strands = ofClamp(strands,0,10);
    [filter setValue:[NSNumber numberWithFloat: strands] forKey:@"inputStrands"];
}
void ofxCIDroste::setZoom(float zoom){
    zoom = ofClamp(zoom,0.1,5);
    [filter setValue:[NSNumber numberWithFloat: zoom] forKey:@"inputZoom"];
}