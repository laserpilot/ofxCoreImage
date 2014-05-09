#pragma once
#include "ofxCIFilter.h"

class ofxCIBarsSwipeTransition : public ofxCIFilter {
    
//This filters takes 2 textures to work - it wipes between 2 images with a blown out copy machine effect
    
public:
 
    void loadFilter();
    //------------------------
    void update(ofTexture tex1, ofTexture tex2);
    //-------------------------
    void setTime(float time);
    //------------------------
    void update(CIImage* inputImage, CIImage* inputBGImage);
    //-------------------------
    void update(CIImage* inputImage, ofTexture tex);
    //-------------------------
    void setAngle(float angle);
    void setBarOffset(int offset);
    void setWidth(int width);

};