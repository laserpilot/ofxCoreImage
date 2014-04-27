#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(0);
    
    sourceFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); //32-bit framebuffer for smoothness
    sourceFbo.begin();
    ofClear(0);
    sourceFbo.end();
    
    setupFilters();
    
    cam.initGrabber(640, 480);
    camEnable = false;
    
    filterNum = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    if(camEnable){
        cam.update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw stuff into FBO so it can be filtered by core image
    sourceFbo.begin();
    ofClear(0,0,0,255); //can set this alpha to 0 to make the FBO transparent but your effects won't necessarily be seen
    
    if(camEnable){
        ofSetColor(255);
        cam.draw(0,0,ofGetWidth(), ofGetHeight());
    }
    
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

    if(filterNum==0){
        blurFilter.setRadius(ofMap(mouseX,0,ofGetWidth(), 0, 20));
        blurFilter.update(sourceFbo.getTextureReference());
        blurFilter.draw(0,0);
    }else if(filterNum==1){
        hueFilter.setAngle(ofMap(mouseX,0,ofGetWidth(), 0, PI));
        hueFilter.update(sourceFbo.getTextureReference());
        hueFilter.draw(0,0);
    }else if(filterNum==2){
        kaleFilter.update(sourceFbo.getTextureReference());
        kaleFilter.setCount(6);
        kaleFilter.setAngle(ofGetElapsedTimef());
        kaleFilter.setCenter(ofGetWidth()/2, ofGetHeight()/2);
        kaleFilter.draw(0,0);
    }else if(filterNum==3){
        crystalFilter.update(sourceFbo.getTextureReference());
        crystalFilter.setRadius(ofMap(mouseX,0,ofGetWidth(), 1, 50));
        crystalFilter.draw(0,0);
    }else if(filterNum==4){
        colorControlFilter.update(sourceFbo.getTextureReference());
        colorControlFilter.setBrightness(ofMap(mouseX,0,ofGetWidth(), 0, 1));
        colorControlFilter.setContrast(ofMap(mouseY,0,ofGetHeight(), 0, 1));
        colorControlFilter.setSaturation(ofMap(mouseX,0,ofGetWidth(), 0, 2));
        colorControlFilter.draw(0,0);
    }else if(filterNum==5){
        pinchFilter.update(sourceFbo.getTextureReference());
        pinchFilter.setRadius(300);
        pinchFilter.setCenter(mouseX,mouseY);
        pinchFilter.setScale(2);
        pinchFilter.draw(0,0);
    }else if(filterNum==6){
        bloomFilter.update(sourceFbo.getTextureReference());
        bloomFilter.setIntensity(ofMap(mouseX,0,ofGetWidth(),0,1));
        bloomFilter.draw(0,0);
    }else if(filterNum==7){
        gloomFilter.update(sourceFbo.getTextureReference());
        gloomFilter.setIntensity(ofMap(mouseX,0,ofGetWidth(),0,1));
        gloomFilter.draw(0,0);
    }else if(filterNum==8){
        bumpFilter.update(sourceFbo.getTextureReference());
        bumpFilter.setRadius(300);
        bumpFilter.setCenter(mouseX,mouseY);
        bumpFilter.setScale(2);
        bumpFilter.draw(0,0);
    }else if(filterNum==9){
        twirlFilter.update(sourceFbo.getTextureReference());
        twirlFilter.setRadius(300);
        twirlFilter.setCenter(mouseX,mouseY);
        twirlFilter.setAngle(ofMap(mouseX,0,ofGetWidth(),-4*PI,4*PI));
        twirlFilter.draw(0,0);
    }else if(filterNum==10){
        vortexFilter.update(sourceFbo.getTextureReference());
        vortexFilter.setRadius(800);
        vortexFilter.setCenter(mouseX,mouseY);
        vortexFilter.setAngle(ofMap(0.5+0.5*sin(ofGetElapsedTimef()),0,1,-30*PI,30*PI));
        vortexFilter.draw(0,0);
    }else if(filterNum==11){
        holeFilter.update(sourceFbo.getTextureReference());
        holeFilter.setRadius(200+100*sin(ofGetElapsedTimef()));
        holeFilter.setCenter(mouseX,mouseY);
        holeFilter.draw(0,0);
    }else if(filterNum==12){
        hexFilter.update(sourceFbo.getTextureReference());
        hexFilter.setCenter(mouseX,mouseY);
        hexFilter.setScale(ofMap(mouseX,0,ofGetWidth(),0,100));
        hexFilter.draw(0,0);
    }else if(filterNum==13){
        circleWrapFilter.update(sourceFbo.getTextureReference());
        circleWrapFilter.setAngle(ofMap(mouseX,0,ofGetWidth(),-PI/2,PI/2));
        circleWrapFilter.setCenter(mouseX, mouseY);
        circleWrapFilter.setRadius(200);
        circleWrapFilter.draw(0,0);
    }else if(filterNum==14){
        wobbleFilter.update(sourceFbo.getTextureReference());
        wobbleFilter.setAngle(ofMap(mouseX,0,ofGetWidth(),0,PI));
        wobbleFilter.setCenter(mouseX, mouseY);
        wobbleFilter.setRadius(200);
        wobbleFilter.setScale(2);
        wobbleFilter.draw(0,0);
    }else if(filterNum==15){
        glassFilter.update(sourceFbo.getTextureReference(), sourceFbo.getTextureReference());
        glassFilter.setScale(3);
        glassFilter.setCenter(mouseX, mouseY);
        glassFilter.draw(0, 0);
    }else if(filterNum==16){
        lozengeFilter.update(sourceFbo.getTextureReference());
        lozengeFilter.setRadius(300);
        lozengeFilter.setRefraction(3);
        lozengeFilter.setPoint0(ofGetWidth()/2, ofGetHeight()/2);
        lozengeFilter.setPoint1(mouseX, mouseY);
        lozengeFilter.draw(0, 0);
    }else if(filterNum==17){
        pixelFilter.update(sourceFbo.getTextureReference());
        pixelFilter.setCenter(mouseX, mouseY);
        pixelFilter.setScale(ofMap(mouseX, 0, ofGetWidth(), 0,100));
        pixelFilter.draw(0, 0);
    }else if(filterNum==18){
        posterizeFilter.update(sourceFbo.getTextureReference());
        posterizeFilter.setLevels(ofMap(mouseX, 0, ofGetWidth(), 2, 20));
        posterizeFilter.draw(0, 0);
    }else if(filterNum==19){
        splashFilter.update(sourceFbo.getTextureReference());
        splashFilter.setCenter(mouseX, mouseY);
        splashFilter.setRadius(200);
        splashFilter.draw(0, 0);
    }else if(filterNum==20){
        drosteFilter.update(sourceFbo.getTextureReference());
        drosteFilter.setPoint1(300, 300);
        drosteFilter.setPoint0(200, 200);
        drosteFilter.setPeriodicity(4);
        drosteFilter.setRotation(ofMap(mouseX,0,ofGetWidth(),0,2*PI));
        drosteFilter.setZoom(1.5+0.5*sin(ofGetElapsedTimef()));
        drosteFilter.setStrands(1);
        drosteFilter.draw(0, 0);
    }else if(filterNum==21){
        edgesFilter.update(sourceFbo.getTextureReference());
        edgesFilter.setIntensity(ofMap(mouseX, 0, ofGetWidth(), 0, 1));
        edgesFilter.draw(0,0);
    }else if(filterNum==22){
        exposureFilter.update(sourceFbo.getTextureReference());
        exposureFilter.setIntensity(ofMap(mouseX, 0, ofGetWidth(), -2, 10));
        exposureFilter.draw(0, 0);
    }else if(filterNum==23){
        gammaFilter.update(sourceFbo.getTextureReference());
        gammaFilter.setPower(ofMap(mouseX, 0, ofGetWidth(), 0.1, 3));
        gammaFilter.draw(0, 0);
    }else if(filterNum==24){
        edgeWorkFilter.update(sourceFbo.getTextureReference());
        edgeWorkFilter.setRadius(ofMap(mouseX, 0, ofGetWidth(), 1, 30));
        edgeWorkFilter.draw(0, 0);
    }else if(filterNum==25){
        invertFilter.update(sourceFbo.getTextureReference());
        invertFilter.draw(0, 0);
    }else if(filterNum==26){
        boxFilter.update(sourceFbo.getTextureReference());
        boxFilter.setRadius(ofMap(mouseX, 0, ofGetWidth(), 0, 15));
        boxFilter.draw(0, 0);
    }else if (filterNum==27){
        circScreenFilter.update(sourceFbo.getTextureReference());
        circScreenFilter.setSharpness(0.5+0.5*sin(ofGetElapsedTimef()));
        circScreenFilter.setCenter(mouseX, mouseY);
        circScreenFilter.setWidth(ofMap(mouseX, 0, ofGetWidth(), 0, 30));
        circScreenFilter.draw(0, 0);
    }else if(filterNum==28){
        lineScreenFilter.update(sourceFbo.getTextureReference());
        lineScreenFilter.setWidth(ofMap(mouseX, 0, ofGetWidth(), 0, 30));
        lineScreenFilter.setAngle(3*ofGetElapsedTimef());
        lineScreenFilter.setCenter(mouseX, mouseY);
        lineScreenFilter.setSharpness(0.5+0.5*sin(ofGetElapsedTimef()));
        lineScreenFilter.draw(0, 0);
    }else if(filterNum==29){
        torusFilter.update(sourceFbo.getTextureReference());
        torusFilter.setCenter(mouseX, mouseY);
        torusFilter.setRadius(300+150*sin(ofGetElapsedTimef()));
        torusFilter.setRefraction(2);
        torusFilter.setWidth(400);
        torusFilter.draw(0, 0);
    }else if(filterNum==30){
        pointyFilter.update(sourceFbo.getTextureReference());
        pointyFilter.setRadius(ofMap(mouseX,0,ofGetWidth(),2,100));
        pointyFilter.setCenter(mouseX, mouseY);
        pointyFilter.draw(0, 0);
    }else if(filterNum==31){
        opTileFilter.update(sourceFbo.getTextureReference());
        opTileFilter.setCenter(mouseX, mouseY);
        opTileFilter.setScale(1);
        opTileFilter.setAngle(ofMap(mouseX,0,ofGetWidth(),-PI,PI));
        opTileFilter.setWidth(65+20*sin(ofGetElapsedTimef()));
        opTileFilter.draw(0,0);
    }else if(filterNum==32){
        motionBlurFilter.update(sourceFbo.getTextureReference());
        motionBlurFilter.setRadius(20);
        motionBlurFilter.setAngle(ofMap(mouseX,0,ofGetWidth(),-180,180));
        motionBlurFilter.draw(0, 0);
    }else if(filterNum==33){
        zoomFilter.update(sourceFbo.getTextureReference());
        zoomFilter.setCenter(mouseX, mouseY);
        zoomFilter.setAmount(ofMap(mouseX, 0, ofGetWidth(), 0, 10));
        zoomFilter.draw(0, 0);
    }
    
    //kaleFilter.draw(0,0);
        ofDrawBitmapStringHighlight("Current Filter: " + ofToString(1+filterNum)+ " /25" , 20,20 );
    ofDrawBitmapStringHighlight("Press ' ' to go to the next filter. \nMove the mouse to control parameters", 20,40 );
    ofDrawBitmapStringHighlight("Press 'c' to activate camera." , 20,80 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' '){
        filterNum++;
        filterNum = filterNum%34;
    }
    
    if(key=='c'){
        camEnable = !camEnable;
    }
}

void ofApp::setupFilters(){
    
    //SET UP ALLLLLL THE FILTERS
    coreBase.setup(); //really not sure if this is necessary yet - but i didnt want to set up multiple CI contexts
    blurFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.getCIContext());
    hueFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    kaleFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    crystalFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    colorControlFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    pinchFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    bloomFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    bumpFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    hexFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    twirlFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    vortexFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    holeFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    circleWrapFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    wobbleFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    glassFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    lozengeFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    pixelFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    posterizeFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    splashFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    drosteFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    edgesFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    exposureFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    gammaFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    gloomFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    edgeWorkFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    invertFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    boxFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    circScreenFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    lineScreenFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    torusFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    pointyFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    opTileFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    motionBlurFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    toneFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    zoomFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    falseColorFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    monoFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    
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
