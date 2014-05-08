#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    
    ofAppGlutWindow window; //CORE IMAGE UNITS ONLY WORK WITH GLUT WINDOW RIGHT NOW - NOT GLFW
    
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    
    // window.setGlutDisplayString("rgba double samples>=4");
    ofSetupOpenGL(&window, 1024,768, OF_WINDOW);
    
	ofRunApp(new ofApp());
    
}
