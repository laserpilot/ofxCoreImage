
#include "ofxCIZoomBlur.h"

void ofxCIZoomBlur::loadFilter(){
    filter = [CIFilter filterWithName:@"CIZoomBlur"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
//-------------------------
void ofxCIZoomBlur::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

//-------------------------
void ofxCIZoomBlur::setAmount(float amount){
    amount = ofClamp(amount,0,200);
    [filter setValue:[NSNumber numberWithFloat: amount] forKey:@"inputAmount"];
}