#include "ofxCIGlassLozenge.h"
 
        
void ofxCIGlassLozenge::loadFilter(){
    filter = [CIFilter filterWithName:@"CIGlassLozenge"];
    [filter setDefaults];
    //always set this on load
}

//-------------------------
//SET VALUES
void ofxCIGlassLozenge::setPoint0(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputPoint0"];
}

void ofxCIGlassLozenge::setPoint1(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputPoint1"];
}

void ofxCIGlassLozenge::setRadius(int radius){
    radius = ofClamp(radius,0,1500);
    [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}

void ofxCIGlassLozenge::setRefraction(float scale){
    scale = ofClamp(scale,-5,5);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputRefraction"];
}