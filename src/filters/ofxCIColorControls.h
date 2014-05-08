#pragma once
#include "ofxCIFilter.h"

class ofxCIColorControls : public ofxCIFilter {
    
    //This CI Filter lets you adjust brightness, saturation and contrast
    
public:
    
    void loadFilter();
    
    //-------------------------
    void setBrightness(float brightness);
    void setContrast(float contrast);
    void setSaturation(float saturation);

};