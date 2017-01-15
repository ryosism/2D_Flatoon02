//
//  StateA.cpp
//  
//
//  Created by 祖父江亮 on 2016/01/23.
//
//

#include "StateA.h"
#include "ofxState.h"

//--------------------------------------------------------------
void stateA::setup(){
    ofBackground(0, 0, 0);
    
    ofSetBackgroundAuto(false);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    ikamodoki.loadFont("ikamodoki1_0.ttf", 30);
    ikamodoki_eng.loadFont("Paintball_Beta_4a.otf", 40);
    kanji.loadFont("ヒラギノ角ゴシック W3.ttc", 40);
    
    rp=0; bp=0;
    resultcheck = true;
    
    int i=0;
    
}

//--------------------------------------------------------------
void stateA::update(){
    
}

//--------------------------------------------------------------
void stateA::draw(){
    ofSetColor(0, 0, 0);
    ofRect(0, 0, 1000, 700);
    ofSetColor(255, 255, 255);
    kanji.drawString("試合結果", ofGetWidth()/2-100, 750);
    
    image.loadImage("result.png");
    image.draw(500, 350);
    
    unsigned char *colorcheck=image.getPixels();
    
    if(resultcheck)//１回だけ実行。
    {
        rp=0; bp=0;
        for(int i=0;i<1000;i+=30)
        {
            for(int j=0;j<700;j+=30)
            {
                int loc = (j*1000+i)*3;
                r=colorcheck[loc];
                b=colorcheck[loc+2];
                ofLog(OF_LOG_NOTICE, "r "+ofToString(r)+"  b "+ofToString(b));
                if(r==255)//赤だったら
                {
                    rp=rp+1;
                    ofLog(OF_LOG_NOTICE, "rp = "+ofToString(rp));
                }
                else if(b==255)//青だったら
                {
                    bp=bp+1;
                    ofLog(OF_LOG_NOTICE,"bp = "+ofToString(bp));
                }
            }
        }
        resultcheck=false;
    }
    ofLog(OF_LOG_NOTICE, "Red = "+ofToString(int(rp))+"  Blue = "+ofToString(int(bp)));
    
    ofSetColor(255, 255, 255);
    ofLine(0, 700, ofGetWidth(), 700);
    
    int full=bp+rp;
    ofLog(OF_LOG_NOTICE, "full : "+ofToString(full));
    r_percent=100*(double)rp/full; b_percent=100*(double)bp/full;
    ofLog(OF_LOG_NOTICE, "Red : "+ofToString(r_percent)+"%   Blue : "+ofToString(b_percent)+"%");
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(255, 0, 0);
    ofRect(0, 750, 10*r_percent, 50);
    ofSetColor(0, 0, 255);
    ofRect(10*r_percent, 750, 10*b_percent, 50);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ikamodoki_eng.loadFont("Paintball_Beta_4a.otf", 40);
    ofSetColor(0,0,0);
    ikamodoki_eng.drawString(ofToString(r_percent,2)+"%", 10*r_percent/2-70, 790);
    ikamodoki_eng.drawString(ofToString(b_percent,2)+"%", 10*r_percent+10*b_percent/2-70, 790);

    ofSetColor(255, 255, 255);
    if(bp>rp)
    {
        ofLog(OF_LOG_NOTICE,"Blue Win");
        ikamodoki_eng.drawString("Win!", 800, 742);
        ikamodoki_eng.drawString("Lose...", 200, 742);
    }
    else if(bp<rp)
    {
        ofLog(OF_LOG_NOTICE,"Red Win");
        ikamodoki_eng.drawString("Win!", 200, 742);
        ikamodoki_eng.drawString("Lose...", 800, 742);
    }
    
//    while(1)
//    {
//        if(i<=1000*r_percent)
//        {
//            ofSetColor(255, 0, 0);
//            ofRect(0, 710, i, 50);
//        }
//        
////        if(i<=1000*b_percent)
////        {
////            ofSetColor(0, 0, 255);
////            ofRect(1000, 710, i*(-1), 50);
////        }
//        
//        i+=10;
//        if(i>1000*r_percent)
//            break;
//    }
}

//----------------------------
string stateA::getName(){
    return "stateA";
}


void stateA::mousePressed(int x , int y, int button){
    //クリックした時に呼び出す
    if (10 < x && x < 60 && 10 < y && y < 60) {
        ofLog(OF_LOG_NOTICE, "touch");
        stateExit();
//        changeState("mainstate");
    }
}


