#include "ofMain.h"

class ISO{
    
public:
    void draw(float rotation);
    void createMesh();
    
    float startAngle;
    float endAngle;
    
    float innerRadius;
    float outerRadius;
    
    bool clockwise;
    int hexColor;
    
    float colorBlueStartFactor;
    float colorBlueEndFactor;
    
    float colorGreenCorrection;
    
    ofMesh mesh;
    ofMesh meshOutline;
    
    
};
