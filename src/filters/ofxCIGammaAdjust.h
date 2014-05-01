#pragma once
#include "ofxCIFilter.h"

class ofxCIGammaAdjust: public ofxCIFilter {
    
public:
    
    //-------------------------
    void loadFilter();
    void setPower(float power);

};