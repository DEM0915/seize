#pragma once

#include "ofMain.h"
#include "ISO.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void createNewISOs();
    void keyPressed(int key);
    void mouseMoved(int x, int y );
    void mouseReleased(int x, int y, int button);
    
    vector<ISO*> ISOs;
    float scale;
    int snapCounter;
    bool bSnapshot;
    ofImage screenGrabber;
    
    
};
