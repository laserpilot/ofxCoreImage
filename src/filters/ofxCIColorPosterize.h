#pragma once
#include "ofxCIFilter.h"

class ofxCIColorPosterize : public ofxCIFilter{
    
    //This CI Filter lets you posterize your image to a set color depth
    
public:

    void loadFilter();
    void setLevels(float levels);

};