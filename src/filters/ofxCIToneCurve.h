#pragma once
#include "ofxCIFilter.h"

class ofxCIToneCurve : public ofxCIFilter {
    
    //This does a tone curve to stuff
    
public:
 
    
    void loadFilter();
    
    //Tone curve goes between 0 and 1
    void setPoint0(int x, int y);
    void setPoint1(int x, int y);
    void setPoint2(int x, int y);
    void setPoint3(int x, int y);
    
};