#pragma once
#include "ofxCIFilter.h"

class ofxCIDissolveTransition : public ofxCIFilter {
    
//This filters takes 2 textures to work - it dissolves between 2 sources based on the 'time' intput from 0 1
    
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

};