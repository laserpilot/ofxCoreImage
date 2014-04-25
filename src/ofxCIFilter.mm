#include "ofxCIFilter.h"

void ofxCIFilter::setup(int width, int height, CIContext* _glCIcontext){

    genericRGB = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
    
    glCIcontext = _glCIcontext;
    
    texSize = CGSizeMake(width, height);
    inRect = CGRectMake(0,0,width,height);
    outRect = CGRectMake(0,0,width,height);
    
    loadFilter();
    
}

void ofxCIFilter::loadFilter(){
    //extend this and load your chosen filter
    filter = [CIFilter filterWithName:@"CIGaussianBlur"];
    [filter setDefaults]; //always set this on load
}
//-------------------------
void ofxCIFilter::update(ofTexture tex){ //this takes an ofTexture and lets you use it as a CI image
    
    texID = tex.texData.textureID;
    
    inputCIImage = [CIImage imageWithTexture:texID
                                        size:texSize
                                     flipped:NO
                                  colorSpace:genericRGB];
    
    [filter setValue:inputCIImage forKey:@"inputImage"];
}
//-------------------------
void ofxCIFilter::update(CIImage* inputImage){
    //don't use both updates with one class...use this for chaining
    [filter setValue:inputImage forKey:@"inputImage"];
}

//-------------------------
void ofxCIFilter::setDefaults(){
    [filter setDefaults];
}
                        
//-------------------------
CIImage* ofxCIFilter::getCIImage(){ //use this to pass into other effects for chaining
    filterCIImage = [filter valueForKey:@"outputImage"];
    return filterCIImage;
}
//--------------------------
void ofxCIFilter::draw(int x, int y){
    
    filterCIImage = [filter valueForKey:@"outputImage"];
    ofPushMatrix();
    ofTranslate(x,y);
    ofSetColor(255);
    [glCIcontext drawImage:filterCIImage
                    inRect:outRect
                  fromRect:inRect];
    ofPopMatrix();
}