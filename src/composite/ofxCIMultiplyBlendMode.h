#pragma once
#include "ofxCIFilter.h"

class ofxCIMultiplyBlendMode: public ofxCIFilter {
    
    
public:
    
    void loadFilter();
    //-----------------------
    void update(ofTexture tex1, ofTexture tex2);
    //------------------------
    void update(CIImage* inputImage, CIImage* inputBGImage);
    //-------------------------
    void update(CIImage* inputImage, ofTexture tex);
};