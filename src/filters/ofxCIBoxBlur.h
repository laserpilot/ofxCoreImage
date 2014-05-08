#pragma once
#include "ofxCIFilter.h"


class ofxCIBoxBlur : public ofxCIFilter {
    
public:
 
    void loadFilter();
    void setRadius(int radius);

};