//
//  mainstate.h
//
//
//  Created by 祖父江亮 on 2016/01/23.
//
//

#ifndef ____mainstate__
#define ____mainstate__

#include <stdio.h>
#include "ofxState.h"

#include "ofApp.h"
#include "panel.h"
#include "ofxTrueTypeFontUC.h"

class mainstate:public itg::ofxState<>
{
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数
    
    
//    void setup();
//    void update();
//    void draw();
    
//    void keyPressed(int key);
//    void keyReleased(int key);
//    void mouseMoved(int x, int y );
//    void mouseDragged(int x, int y, int button);
//    void mousePressed(int x, int y, int button);
//    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int linex,liney,px,py,qx,qy,playtime,gp1,gp2;
    int direc1,direc2;
    int game;
    
    Panel *panel;
    ofxTrueTypeFontUC ikamodoki;
    ofTrueTypeFont ikamodoki_eng;
    
    
    
};


#endif /* defined(____mainstate__) */
