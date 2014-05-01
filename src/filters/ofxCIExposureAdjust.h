#pragma once
#include "ofxCIFilter.h"

class ofxCIExposureAdjust : public ofxCIFilter {
    
public:

    //-------------------------
    void loadFilter();
    void setIntensity(float intensity);

};