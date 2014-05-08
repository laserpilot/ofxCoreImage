

#pragma once
#include "ofxCIFilter.h"


class ofxCIBlur : public ofxCIFilter
{
    
    //This applies a gaussian blur CI FIlter
    
public:
    
    void loadFilter();
    void setRadius(int radius);
    
};