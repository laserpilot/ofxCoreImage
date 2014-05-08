#pragma once
#include "ofxCIFilter.h"

class ofxCISourceAtopCompositing : public ofxCIFilter {
    //Additive blending of 2 sources
    
public:
    
    void loadFilter();
    //-----------------------
    void update(ofTexture tex1, ofTexture tex2);
    //------------------------
    void update(CIImage* inputImage, CIImage* inputBGImage);
    //-------------------------
    void update(CIImage* inputImage, ofTexture tex);
};