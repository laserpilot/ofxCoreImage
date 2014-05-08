
#include "ofxCIPixellate.h"

void ofxCIPixellate::loadFilter(){
    filter = [CIFilter filterWithName:@"CIPixellate"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCIPixellate::setScale(float scale){
    scale = ofClamp(scale,1, 100);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}
//-------------------------
void ofxCIPixellate::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}