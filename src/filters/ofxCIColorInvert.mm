
#include "ofxCIColorInvert.h"

void ofxCIColorInvert::loadFilter(){
    filter = [CIFilter filterWithName:@"CIColorInvert"];
    [filter setDefaults]; //always set this on load
}
