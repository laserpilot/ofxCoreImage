
#include "ofxCIOpTile.h"

void ofxCIOpTile::loadFilter(){
    filter = [CIFilter filterWithName:@"CIOpTile"];
    [filter setDefaults]; //always set this on load
}

//-------------------------
void ofxCIOpTile::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

//-------------------------
void ofxCIOpTile::setAngle(float angle){
    angle = ofWrap(angle,-PI, PI);
    [filter setValue:[NSNumber numberWithFloat: angle] forKey:@"inputAngle"];
}
//-------------------------
void ofxCIOpTile::setWidth(float width){
    width = ofClamp(width,1, 1000);
    [filter setValue:[NSNumber numberWithFloat: width] forKey:@"inputWidth"];
}
//-------------------------
void ofxCIOpTile::setScale(float scale){
    scale = ofClamp(scale,0.1, 10);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}