#pragma once
#include "ofxCIFilter.h"

class ofxCIPinchDistortion : public ofxCIFilter {

public:
    void loadFilter();
    //-------------------------
    void setCenter(int x, int y);
    void setRadius(int radius);
    void setScale(float scale);

};