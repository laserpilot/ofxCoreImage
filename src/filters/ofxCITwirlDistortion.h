#pragma once
#include "ofxCIFilter.h"

class ofxCITwirlDistortion : public ofxCIFilter {
    
    //This applies a twirl distortion filter
    
public:
 
    void loadFilter();
    
    //-------------------------
    //SET VALUES
    void setCenter(int x, int y);
    void setRadius(int radius);
    void setAngle(float angle);
};