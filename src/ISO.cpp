#include "ISO.hpp"

void ISO::createMesh(){
    
    float x,y;
    float angle;
    
    float angleSteps = 10 / innerRadius;
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    meshOutline.setMode(OF_PRIMITIVE_LINE_LOOP);
    
    
    int index = 0;
    float colorBlue = colorBlueStartFactor;
    float colorBlueSteps = (colorBlueEndFactor - colorBlueStartFactor) / ((endAngle-startAngle)/angleSteps);
    
    vector<ofVec3f> innerCircleMeshOutline;
    
    for (float angle = startAngle; angle <= endAngle; angle+=angleSteps){
        
        colorBlue += colorBlueSteps;
        x = outerRadius * cos(angle);
        y = outerRadius * sin(angle);
        
        mesh.addVertex(ofVec3f(x,y,0));
        meshOutline.addVertex(ofVec3f(x,y,0));
        mesh.addColor(ofFloatColor(0,colorBlue,colorBlue - colorGreenCorrection));
        
        x = innerRadius * cos(angle);
        y = innerRadius * sin(angle);
        
        mesh.addVertex(ofVec3f(x,y,0));
        
        innerCircleMeshOutline.push_back(ofVec3f(x,y,0));
        
        mesh.addColor(ofFloatColor(0,colorBlue,colorBlue - colorGreenCorrection));
        
    }
    
    std::reverse(innerCircleMeshOutline.begin(), innerCircleMeshOutline.end());
    meshOutline.addVertices(innerCircleMeshOutline);
    
}


void ISO::draw(float rotation){
    
    glPushMatrix();
    
    ofRotateZ(rotation * ((clockwise) ? 1 : -1));
    
    ofSetLineWidth(1);
    ofSetColor(0, 60, 60);
    meshOutline.drawFaces();
    
    ofSetLineWidth(0);
    mesh.drawFaces();
    
    glPopMatrix();
}
