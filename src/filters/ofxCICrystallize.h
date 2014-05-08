#pragma once
#include "ofxCIFilter.h"

class ofxCICrystallize : public ofxCIFilter{
    
    //This CI Filter does a crystallize filter
    
public:
 
    void loadFilter();
    //-------------------------
    void setRadius(float radius);
    
};