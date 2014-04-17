#pragma once

#include "ofMain.h"
#include "ofxCoreImage.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void setupFilters();
    
    ofVideoGrabber cam;
    bool camEnable;
    
    int filterNum;
    
    ofxCI coreBase;
    ofxCIBlur blurFilter;
    ofxCIHue hueFilter;
    ofxCIKaleidoscope kaleFilter;
    ofxCICrystallize crystalFilter;
    ofxCIColorControls colorControlFilter;
    ofxCIPinchDistortion pinchFilter;
    ofxCIBloom bloomFilter;
    ofxCIBumpDistortion bumpFilter;
    ofxCIHexagonalPixellate hexFilter;
    ofxCITwirlDistortion twirlFilter;
    ofxCIVortexDistortion vortexFilter;
    ofxCIHoleDistortion holeFilter;
    ofxCICircularWrap circleWrapFilter;
    ofxCIBumpDistortionLinear wobbleFilter;
    ofxCIGlassDistortion glassFilter;
    ofxCIGlassLozenge lozengeFilter;
    ofxCIPixellate pixelFilter;
    ofxCIColorPosterize posterizeFilter;
    ofxCICircleSplashDistortion splashFilter;
    ofxCIDroste drosteFilter;
    ofxCIEdges edgesFilter;
    ofxCIExposureAdjust exposureFilter;
    ofxCIGammaAdjust gammaFilter;
    ofxCIGloom gloomFilter;
    ofxCIEdgeWork edgeWorkFilter;
    ofxCIColorInvert invertFilter;
    ofxCIBoxBlur boxFilter;
    ofxCICircularScreen circScreenFilter;
    ofxCILineScreen lineScreenFilter;
    ofxCITorusLensDistortion torusFilter;
    ofxCIPointillize pointyFilter;
    ofxCIOpTile opTileFilter;
    ofxCIMotionBlur motionBlurFilter;
    ofxCIToneCurve toneFilter;
    ofxCIZoomBlur zoomFilter;
    ofxCIFalseColor falseColorFilter;
    ofxCIColorMonochrome monoFilter;
    
    ofFbo sourceFbo;
		
};
