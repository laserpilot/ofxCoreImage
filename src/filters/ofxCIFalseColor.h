#pragma once
#include "ofxCIFilter.h"

class ofxCIFalseColor:public ofxCIFilter{
    
    //this filter remaps the color range of your input between 2 given colors...ideally a dark and light one
    
public:
 
    void loadFilter();
    void setColor1(ofColor color1);
    void setColor2(ofColor color2);

};