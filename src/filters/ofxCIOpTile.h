#pragma once
#include "ofxCIFilter.h"

class ofxCIOpTile : public ofxCIFilter{
    
    //This CI Filter lets you adjust brightness, saturation and contrast
    //Set: setAngle, setCenter, setCount
    
public:
    
    void loadFilter();
    //-------------------------
    void setCenter(int x, int y);
    //-------------------------
    void setAngle(float angle);
    //-------------------------
    void setWidth(float width);
    //-------------------------
    void setScale(float scale);

};