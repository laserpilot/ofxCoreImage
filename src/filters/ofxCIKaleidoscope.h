#pragma once
#include "ofxCIFilter.h"

class ofxCIKaleidoscope: public ofxCIFilter {
    
    //This CI Filter applies a kaleidoscope effect to the input
    //Set: setAngle, setCenter, setCount
    
public:
 
    void loadFilter();
    //-------------------------
    void setAngle(float angle);
    //-------------------------
    void setCenter(int x, int y);
    //-------------------------
    void setCount(int count);
};