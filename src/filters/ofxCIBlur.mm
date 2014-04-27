
#include "ofxCIBlur.h"

void ofxCIBlur::loadFilter(){
    filter = [CIFilter filterWithName:@"CIGaussianBlur"];
    [filter setDefaults];
}
    
void ofxCIBlur::setRadius(int radius){
                radius = ofClamp(radius,0,50);
               [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
    

    
