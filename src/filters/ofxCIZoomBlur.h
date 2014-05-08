#pragma once
#include "ofxCIFilter.h"

class ofxCIZoomBlur : public ofxCIFilter {
    //this applies a sort of radial/zoom blur
public:
 
    
    void loadFilter();
    
    //-------------------------
    void setCenter(int x, int y);

    //-------------------------
    void setAmount(float amount);

};