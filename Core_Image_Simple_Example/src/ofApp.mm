#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sourceFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); //32-bit framebuffer for smoothness
    sourceFbo.begin();
    ofClear(0);
    sourceFbo.end();
    
    coreBase.setup(); //really not sure if this is necessary yet - but i didnt want to set up multiple ci contexts
    blurFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    hueFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    kaleFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    //Pass your FBO into the CI filters
    blurFilter.update(sourceFbo.getTextureReference());
    blurFilter.setRadius(ofMap(mouseX,0,ofGetWidth(), 0, 20));
    hueFilter.update(blurFilter.getCIImage());
    hueFilter.setAngle(ofMap(mouseX,0,ofGetWidth(), 0, PI));
    kaleFilter.update(hueFilter.getCIImage());
    kaleFilter.setCount(6);
    kaleFilter.setAngle(ofGetElapsedTimef());
    kaleFilter.setCenter(ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw stuff into FBO so it can be filtered by core image
    sourceFbo.begin();
    //ofClear(0,0,0,255); //can set this alpha to 0 to make the FBO transparent but your effects won't necessarily be seen
    
    ofSetColor(20, 130, 250);
    ofNoFill();
    ofSetLineWidth(40);
    ofCircle(ofGetWidth()/2,ofGetWidth()/2,10+(ofGetFrameNum()%40)*6);
    
    ofFill();
    ofSetColor(255);
    for (int i=0; i<10; i++) {
        ofSetColor(20*i, 10*i, 250);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofRect(ofGetWidth()/2+200*sin(i*0.7+0.5*ofGetElapsedTimef()), ofGetHeight()/2+200*cos(i*0.7+0.5*ofGetElapsedTimef()), 100,100);
    }
    ofSetRectMode(OF_RECTMODE_CORNER);
    sourceFbo.end();
    
    kaleFilter.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
