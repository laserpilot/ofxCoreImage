
#include "ofxCIEdges.h"

void ofxCIEdges::loadFilter(){
    filter = [CIFilter filterWithName:@"CIEdges"];
    [filter setDefaults]; //always set this on load
}
//-------------------------
void ofxCIEdges::setIntensity(float intensity){
    intensity = ofClamp(intensity ,0, 1);
    [filter setValue:[NSNumber numberWithFloat: intensity] forKey:@"inputIntensity"];
}