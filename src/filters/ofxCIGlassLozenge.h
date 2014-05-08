#pragma once
#include "ofxCIFilter.h"

class ofxCIGlassLozenge: public ofxCIFilter {
    
    //This applies an effect thats like having a glass pill over top of the image complete with refraction changes
    
public:
    
    void loadFilter();
    
    //-------------------------
    //SET VALUES
    void setPoint0(int x, int y);
    void setPoint1(int x, int y);
    void setRadius(int radius);
    void setRefraction(float scale);

};