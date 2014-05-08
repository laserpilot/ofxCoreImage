#pragma once
#include "ofxCIFilter.h"

class ofxCIDroste : public ofxCIFilter{
    
    //This applies a droste style effect with variable zoom and focus points
    
public:
 
    void loadFilter();
    //-------------------------
    //SET VALUES
    void setPoint0(int x, int y);
    void setPoint1(int x, int y);
    void setPeriodicity(int periodicity);
    void setRotation(float rotation);
    void setStrands(float strands);
    void setZoom(float zoom); 

};