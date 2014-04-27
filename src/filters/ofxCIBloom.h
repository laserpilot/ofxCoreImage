//
//  ofxEasyCI.h
//  coreImage_sketch
//
//  Created by Blair Neal on 4/15/14.
//
//

#pragma once
#include "ofxCIFilter.h"

class ofxCIBloom: public ofxCIFilter{
    
    //This applies a Bloom filter
    
public:
 

        
    void loadFilter();
    void setRadius(int radius);
    void setIntensity(float intensity);
    

};