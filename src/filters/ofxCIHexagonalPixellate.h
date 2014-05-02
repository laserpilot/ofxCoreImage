#pragma once
#include "ofxCIFilter.h"

class ofxCIHexagonalPixellate : public ofxCIFilter {
    
    //This CI Filter pixellates the image with hexagon tiles
    
public:
 
    void loadFilter();
    //-------------------------
    void setScale(float scale);
    //-------------------------
    void setCenter(int x, int y);
    
};