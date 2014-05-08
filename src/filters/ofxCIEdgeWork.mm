
#include "ofxCIEdgeWork.h"

void ofxCIEdgeWork::loadFilter(){
    filter = [CIFilter filterWithName:@"CIEdgeWork"];
    [filter setDefaults]; //always set this on load
}
//-------------------------
void ofxCIEdgeWork::setRadius(float radius){
    radius = ofClamp(radius,0, 20);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}