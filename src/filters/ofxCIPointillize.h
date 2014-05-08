#pragma once
#include "ofxCIFilter.h"

class ofxCIPointillize : public ofxCIFilter {
    
public:
 
    void loadFilter();
    //-------------------------
    void setRadius(float radius);
    //-------------------------
    void setCenter(int x, int y);

};