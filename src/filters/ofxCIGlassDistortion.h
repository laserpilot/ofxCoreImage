#pragma once
#include "ofxCIFilter.h"

class ofxCIGlassDistortion: public ofxCIFilter {
        //this filter takes another texture that does a slight texturization/displacement of the source image, like carved glass
    
public:
 
    
    void loadFilter();

    
    //-----------------------
    void update(ofTexture tex1, ofTexture tex2);
    //------------------------
    void update(CIImage* inputImage, CIImage* inputBGImage);
    //-------------------------
    void update(CIImage* inputImage, ofTexture tex);
    
    //-------------------------
    //SET VALUES
    void setCenter(int x, int y);
    void setScale(float scale);

    
    

};