#pragma once
#include "ofxCIFilter.h"

class ofxCILineScreen:public ofxCIFilter{
    
    //This CI Filter masks the image with a stack of lines that thicken based on luminosity
    
public:
 
    void loadFilter();
    
    //-------------------------
    void setSharpness(float sharpness);
    void setWidth(float scale);
    void setCenter(int x, int y);
    void setAngle(float angle);
    
};