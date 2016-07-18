#include "ofApp.h"

int nrOfCircles = 1;
float rotation = 0;
float rotationSteps = 0.01;
float lastSwitch;
bool closing;
bool opening;


void ofApp::setup(){
    
    ofBackground(0, 0, 0, 253);
    rotationSteps= 0.4;
    snapCounter =0;
    scale=0;
    
    
    ofSetVerticalSync(false);
    bSnapshot = false;
    closing = false;
    opening = true;
    createNewISOs();
    ofHideCursor();
    ofSetFrameRate(60);
    
    lastSwitch = ofGetElapsedTimef();
}


void ofApp::update(){
    
    rotation += rotationSteps;
    
    if(ofGetElapsedTimef() - lastSwitch > 9 && !closing && !opening)
    {
        closing =true;
        opening = false;
    }
    
    if (closing) {
        scale -=(scale) / 8;
        
        if(scale < 0.1)
        {
            createNewISOs();
            opening = true;
            closing = false;
        }
    }
    
    if (opening) {
        scale+=(1-scale) / 8;
        if(scale > 0.99)
        {
            scale = 1;
            lastSwitch = ofGetElapsedTimef();
            opening = false;
        }
    }
    
}


void ofApp::draw(){
    
    glTranslatef(ofGetWidth()/2,ofGetHeight()/2,0);
    
    ofScale(scale, scale, 1);
    
    for (int i=0; i < nrOfCircles; i++)
    {
        ISO* ISOObject = ISOs.at(i);
        ISOObject->draw(rotation);
    }
    
    if (bSnapshot == true){
        screenGrabber.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        char fileName[255];
        sprintf(fileName, "SL55_%3i.png", snapCounter++);
        screenGrabber.save(fileName);
        bSnapshot = false;
    }
}



void ofApp::createNewISOs(){
    
    for (int i=0; i < ISOs.size(); i++) {
        
        delete ISOs[i];
    }
    
    ISOs.clear();
    
    nrOfCircles = 4 + ofRandom(70);
    
    float innerRadius = 100;
    float angle=0;
    float cirleAngle =0;
    float lineWidth = 10;
    float margin = 0;
    float circleStartAngle = 0;
    
    bool clockWise = true;
    
    for (int i=0; i < nrOfCircles; i++) {
        
        ISO* ISOObject = new ISO();
        ISOObject->innerRadius = innerRadius;
        ISOObject->outerRadius = innerRadius + lineWidth;
        
        angle += ofRandom(0,10) > 2 ? 0.1 : 0;
        ISOObject->startAngle = angle;
        
        angle += ofRandom(0.2,4.5);
        ISOObject->endAngle = angle;
        ISOObject->clockwise = clockWise;
        
        
        ISOObject->colorBlueStartFactor = ofClamp(ofRandom(-0.4,1.0), 0, 1);
        ISOObject->colorBlueEndFactor = ofClamp(ofRandom(-0.4,1.0), 0, 1);
        ISOObject->colorGreenCorrection = ofClamp(ofRandom(-0.4,0.1), 0, 1);
        
        
        if (angle >= ( TWO_PI + circleStartAngle  )) {
            
            innerRadius += (margin + lineWidth) ;
            ISOObject->endAngle = TWO_PI + circleStartAngle ;
            
            angle= (angle - ( TWO_PI));
            circleStartAngle = angle;
            clockWise = ofRandom(10) > 5;
            
            
            int lineWidthRandom = ofRandom(20);
            if (lineWidthRandom < 3) {
                lineWidth = 30;
            }else if (lineWidth <10) {
                lineWidth = 20;
            }else {
                lineWidth =10;
            }
            
            
            int marginRandom = ofRandom(0,20);
            
            if(marginRandom > 6){
                margin =0;
            }
            else if(marginRandom > 2){
                margin =10;
            }else
            {
                margin =30;
            }
        }
        
        ISOObject->createMesh();
        ISOs.push_back(ISOObject);
        
    }
}

void ofApp::keyPressed(int key){
    
    if (key == 's')bSnapshot = true;
    
}

void ofApp::mouseMoved(int x, int y ){
    
    rotationSteps= x / (ofGetWidth() / 2.0);
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
    closing =true;
    opening = false;
    lastSwitch = ofGetElapsedTimef();
    
}
