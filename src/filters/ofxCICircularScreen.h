#pragma once
#include "ofxCIFilter.h"

class ofxCICircularScreen:public ofxCIFilter {
    
    //This CI Filter applies a circular screen mask that draws the image in concentric circles
    
public:
    void loadFilter();
    
    //-------------------------
    void setSharpness(float sharpness);
    void setWidth(float scale);
    void setCenter(int x, int y);

};