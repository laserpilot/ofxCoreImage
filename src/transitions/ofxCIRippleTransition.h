#pragma once
#include "ofxCIFilter.h"

class ofxCIRippleTransition : public ofxCIFilter {
    
//This filters takes 3 textures to work - you need a shading texture and a target/source texture. You can also just send one of those to the shading target if you want. I think it just adds normals and specularity to the "water" ripples
    
public:
 
    
    void loadFilter();

    //------------------------
    void update(ofTexture tex1, ofTexture tex2);
    //------------------------
    void updateShadingTexture(ofTexture tex);
    //-------------------------
    void setScale(float scale);
    //-------------------------
    void setExtent(int x, int y, int width, int height);
    //-------------------------
    void setTime(float time);
    //-------------------------
    void setCenter(int x, int y);
    //-------------------------
    void setWidth(float width);
    //------------------------
    void update(CIImage* inputImage, CIImage* inputBGImage);
    //-------------------------
    void update(CIImage* inputImage, ofTexture tex);

    

};