
#include "ofxCIBoxBlur.h"

void ofxCIBoxBlur::loadFilter(){
    filter = [CIFilter filterWithName:@"CIBoxBlur"];
    [filter setDefaults]; //always set this on load

}
    
void ofxCIBoxBlur::setRadius(int radius){
                radius = ofClamp(radius,0,50);
               [filter setValue:[NSNumber numberWithFloat: radius] forKey:@"inputRadius"];
}
    

    
