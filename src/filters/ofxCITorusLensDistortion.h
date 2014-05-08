#pragma once
#include "ofxCIFilter.h"

class ofxCITorusLensDistortion : public ofxCIFilter {
    
    
public:
 
    
    void loadFilter();
    
    void setCenter(int x, int y);
    //------------------------
    void setRadius(int radius);
    //-------------------------
    void setWidth(float scale);
    //-------------------------
    void setRefraction(float scale);

};