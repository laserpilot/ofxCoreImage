
#include "ofxCICrystallize.h"

void ofxCICrystallize::loadFilter(){
    filter = [CIFilter filterWithName:@"CICrystallize"];
    [filter setDefaults]; //always set this on load
}
//------------
//-------------------------
void ofxCICrystallize::setRadius(float radius){
    radius = ofClamp(radius,1, 50);
    
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}