#pragma once

#include "ofxCIFilter.h"

class ofxCIHue : public ofxCIFilter
{
    
    //This CI Filter lets you adjust the hue from 0-PI
    
public:

    void loadFilter();
    void setAngle(float angle);
    
};