#include "ofxCIHue.h"
 
        
void ofxCIHue::loadFilter(){
    filter = [CIFilter filterWithName:@"CIHueAdjust"];
    [filter setDefaults];
    //always set this on load
}

void ofxCIHue::setAngle(float angle){
    angle = ofWrap(angle,0, PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}

    
