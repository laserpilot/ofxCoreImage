#pragma once
#include "ofxCIFilter.h"

class ofxCIMotionBlur : public ofxCIFilter {
    
    //this filter applies an angled blur - does not actually react to motion :(
public:
 
    void loadFilter();
    //------------------------
    void setRadius(int radius);
    //------------------------
    void setAngle(float angle);
    
 };