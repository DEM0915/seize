#include "ofApp.h"

int nrOfCircle = 1;
float rotation = 0;
float rotationSteps = 0.01;
float lastSwitch;
bool closing;
bool opening;

void ofApp::setup(){
    
    ofBackground(0, 0, 0, 253);
    ofSetFrameRate(60);
    ofSetVerticalSync(false);
    lastSwitch = ofGetElapsedTimef();
    
    closing = false;
    opening = true;
    rotationSteps = 0.4;
    
    

}


void ofApp::update(){
    
    rotation += rotationSteps;

}


void ofApp::draw(){
    
    ofSetTranlate(ofGetWidth()/2, ofGetHeight()/2, 0);

}






void ofApp::mouseReleased(int x, int y, int button){}
