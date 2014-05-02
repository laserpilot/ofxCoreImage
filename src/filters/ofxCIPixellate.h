#pragma once
#include "ofxCIFilter.h"

class ofxCIPixellate : public ofxCIFilter {

    
public:
 
    void loadFilter();
    //-------------------------
    void setScale(float scale);
    //-------------------------
    void setCenter(int x, int y);

};