
#include "ofxCIGlassDistortion.h"

void ofxCIGlassDistortion::loadFilter(){
    filter = [CIFilter filterWithName:@"CIGlassDistortion"];
    [filter setDefaults]; //always set this on load
}

//-----------------------
void ofxCIGlassDistortion::update(ofTexture tex1, ofTexture tex2){ //first texture and then displacement texture in grayscale
    
    texID = tex1.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    texID2 = tex2.texData.textureID;
    
    inputBGCIImage = [CIImage imageWithTexture:texID2
                                          size:texSize
                                       flipped:NO
                                    colorSpace:genericRGB];
    
    [filter setValue:inputCIImage forKey:@"inputImage"];
    [filter setValue:inputBGCIImage forKey:@"inputTexture"];
}
//------------------------
void ofxCIGlassDistortion::update(CIImage* inputImage, CIImage* inputBGImage){//don't use both updates with one class...use this for chaining
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputBGImage forKey:@"inputTexture"];
}
//-------------------------
void ofxCIGlassDistortion::update(CIImage* inputImage, ofTexture tex){ //mix an OF texture and a CI filtered image
    
    texID = tex.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    
    [filter setValue:inputImage forKey:@"inputImage"];
    [filter setValue:inputCIImage forKey:@"inputTexture"];
}


//-------------------------
//SET VALUES
void ofxCIGlassDistortion::setCenter(int x, int y) {
    [filter  setValue:[CIVector vectorWithX:x Y:y] forKey:@"inputCenter"];
}

void ofxCIGlassDistortion::setScale(float scale){
    scale = ofClamp(scale,0,500);
    [filter setValue:[NSNumber numberWithFloat: scale] forKey:@"inputScale"];
}