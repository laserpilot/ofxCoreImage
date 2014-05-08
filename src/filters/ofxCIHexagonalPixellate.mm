#include "ofxCIHexagonalPixellate.h"

void ofxCIHexagonalPixellate::loadFilter(){
    filter = [CIFilter filterWithName:@"CIHexagonalPixellate"];
    [filter setDefaults]; 
}
//-------------------------
void ofxCIHexagonalPixellate::setScale(float scale){
    scale = ofClamp(scale,1, 100);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}
//-------------------------
void ofxCIHexagonalPixellate::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}