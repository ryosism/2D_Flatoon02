//
//  StateA.h
//  
//
//  Created by 祖父江亮 on 2016/01/23.
//
//

#ifndef ____StateA__
#define ____StateA__

#include <stdio.h>
#include "ofxState.h"
#include "ofxTrueTypeFontUC.h"

class stateA:public itg::ofxState<>
{
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数
    
    ofxTrueTypeFontUC ikamodoki;
    ofxTrueTypeFontUC kanji;
    ofTrueTypeFont ikamodoki_eng;
    
    ofImage image;
    
//    unsigned char *colorcheck;
    int rp,bp;
    bool resultcheck;
    int r,g,b,i;
    
    double r_percent,b_percent;
};


#endif /* defined(____StateA__) */
