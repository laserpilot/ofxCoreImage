#pragma once
#include "ofxCIFilter.h"

class ofxCICircleSplashDistortion : public ofxCIFilter{
    
public:
    
    void loadFilter();
    //-------------------------
    void setCenter(int x, int y);
    void setRadius(int radius);

};