#pragma once
#include "ofxCIFilter.h"

class ofxCIColorMonochrome : public ofxCIFilter{
    
    //This filter lets you set a monochrome color for the input image
    
public:

    void loadFilter();
    //-------------------------
    void setColor(ofColor color1);
    //------------------------
    void setIntensity(float intensity);

};