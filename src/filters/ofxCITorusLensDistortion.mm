
#include "ofxCITorusLensDistortion.h"

void ofxCITorusLensDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CITorusLensDistortion"];
    [filter setDefaults]; //always set this on load
}

//SET VALUES
//-------------------------
void ofxCITorusLensDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}
//------------------------
void ofxCITorusLensDistortion::setRadius(int radius){
    radius = ofClamp(radius,0,1000);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}

//-------------------------
void ofxCITorusLensDistortion::setWidth(float scale){
    scale = ofClamp(scale,0, 600);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputWidth"];
}
//-------------------------
void ofxCITorusLensDistortion::setRefraction(float scale){
    scale = ofClamp(scale,-5,5);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputRefraction"];
}