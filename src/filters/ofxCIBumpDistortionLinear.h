
#pragma once
#include "ofxCIFilter.h"

class ofxCIBumpDistortionLinear : public ofxCIFilter {
    
public:
    //-------------------------
    //SET VALUES
    void loadFilter();
    void setCenter(int x, int y);
    void setRadius(int radius);
    void setScale(float scale);
    void setAngle(float angle);

};