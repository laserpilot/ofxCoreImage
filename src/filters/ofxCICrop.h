

#pragma once
#include "ofxCIFilter.h"


class ofxCICrop : public ofxCIFilter
{
    
    //This applies a gaussian blur CI FIlter
    
public:
    
    void loadFilter();
    void setRectangle(int x, int y, int width, int height);
    
};