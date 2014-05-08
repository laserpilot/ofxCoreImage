#pragma once
#include "ofxCIFilter.h"

class ofxCIHoleDistortion : public ofxCIFilter{
    
public:
 
    void loadFilter();
    //-------------------------
    //SET VALUES
    void setCenter(int x, int y);
    void setRadius(int radius);

};