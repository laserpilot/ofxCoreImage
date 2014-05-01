//
//  ofxEasyCI.h
//  coreImage_sketch
//
//  Created by Blair Neal on 4/15/14.
//
//

#pragma once
#include "ofxCIFilter.h"

class ofxCIGloom:public ofxCIFilter{
    
    //This applies a Gloom filter that darkens highlights - almost an inverse bloom
    
public:
    
    void loadFilter();
    void setRadius(int radius);
    void setIntensity(float intensity);
};