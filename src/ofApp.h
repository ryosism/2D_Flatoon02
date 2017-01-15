#pragma once

#include "ofMain.h"
#include "panel.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxStateMachine.h"

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
    
    int linex,liney,px,py,qx,qy,playtime,gp1,gp2;
    int direc1,direc2;
    int game;
    bool startflag,opening;
    
    Panel *panel;
    ofxTrueTypeFontUC ikamodoki;
    ofxTrueTypeFontUC kanji;
    ofTrueTypeFont ikamodoki_eng;
    ofImage image;
    
    itg::ofxStateMachine<> stateMachine;
    
};