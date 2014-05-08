
#include "ofxCIColorPosterize.h"

void ofxCIColorPosterize::loadFilter(){
    filter = [CIFilter filterWithName:@"CIColorPosterize"];
    [filter setDefaults]; //always set this on load
}
//------------
void ofxCIColorPosterize::setLevels(float levels){
    levels = ofClamp(levels,2, 30);
    [filter setValue:[NSNumber numberWithFloat: levels] forKey:@"inputLevels"];
}