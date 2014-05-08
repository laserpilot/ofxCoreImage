#pragma once
#include "ofxCIFilter.h"

class ofxCICircularWrap : public ofxCIFilter{
    
    
public:
 
    
    void loadFilter();
    
    //-------------------------
    //SET VALUES
    void setCenter(int x, int y);
    void setRadius(int radius);
    void setAngle(float angle);
};