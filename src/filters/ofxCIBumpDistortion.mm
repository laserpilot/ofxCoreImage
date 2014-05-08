
#include "ofxCIBumpDistortion.h"

void ofxCIBumpDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CIBumpDistortion"];
    [filter setDefaults]; //always set this on load

}

void ofxCIBumpDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

void ofxCIBumpDistortion::setRadius(int radius){
    radius = ofClamp(radius,0,600);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
void ofxCIBumpDistortion::setScale(float scale){
    scale = ofClamp(scale,-1,1);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}

