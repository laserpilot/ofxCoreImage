
#include "ofxCICrop.h"

void ofxCICrop::loadFilter(){
    filter = [CIFilter filterWithName:@"CICrop"];
    [filter setDefaults];
}
    
void ofxCICrop::setRectangle(int x, int y, int width, int height){
    [filter setValue:[CIVector vectorWithX:x Y:y Z:width W:height] forKey:@"inputRectangle"];
}

    
