#pragma once
#include "ofxCIFilter.h"

class ofxCIBumpDistortion : public ofxCIFilter {
    
    //This applies a bump filter that is positionable and scaleable
    
public:
    
    //-------------------------
    void loadFilter();
    void setCenter(int x, int y);
    void setRadius(int radius);
    void setScale(float scale);

};